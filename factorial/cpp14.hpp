#include <stdexcept>
#include <cassert>
#include <tuple>
#include "runtimeFactorial.hpp"

namespace cpp14 {

// template factorial (nothing specific to cpp14)
template<int x, typename = typename std::enable_if<(x >= 0)>::type>
struct structFactorial {
    enum {
        value = x * structFactorial<x - 1>::value
    };
};

template<>
struct structFactorial<0> {
    enum {
        value = 1
    };
};

// constexpr factorial
constexpr int constexprFactorial(int x) {
    // throw idiom
    if (x < 0)
        throw std::runtime_error{"Factorial argument must be non-negative"};
    if (x == 0)
        return 1;

    return x * constexprFactorial(x - 1);
}

}

auto testCpp14() {
    const int arg = 5;

    auto runtimeRes = ::runtimeFactorial(arg);
    constexpr auto templateFact = cpp14::structFactorial<arg>::value;
    constexpr auto constexprFact = cpp14::constexprFactorial(arg);

    // constexpr auto badCall1 = cpp14::structFactorial<-1>::value;
    // constexpr auto badCall2 = cpp14::constexprFactorial(-1);

    static_assert(
        templateFact == constexprFact
    );

    assert (runtimeRes == templateFact && templateFact == constexprFact);

    return std::tuple<int, int>{arg, runtimeRes};
}