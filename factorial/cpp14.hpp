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

// constexpr recursive
constexpr int recursiveConstexprFactorial(int x) {
    // throw idiom
    if (x < 0)
        throw std::runtime_error{"Factorial argument must be non-negative"};
    if (x == 0)
        return 1;

    return x * recursiveConstexprFactorial(x - 1);
}

// constexpr iterative
constexpr int iterativeConstexprFactorial(int x) {
    // throw idiom
    if (x < 0)
        throw std::runtime_error{"Factorial argument must be non-negative"};

    auto res = 1;
    while (x > 0)
        res *= x--;

    return res;
}

}

inline auto testCpp14() {
    const int arg = 5;

    auto runtimeRes = ::runtimeFactorial(arg);
    constexpr auto templateFact = cpp14::structFactorial<arg>::value;
    constexpr auto recursiveConstexprFact = cpp14::recursiveConstexprFactorial(arg);
    constexpr auto iterativeConstexprFact = cpp14::iterativeConstexprFactorial(arg);

    // constexpr auto badCall1 = cpp14::structFactorial<-1>::value;
    // constexpr auto badCall2 = cpp14::constexprFactorial(-1);

    static_assert(
        templateFact == iterativeConstexprFact && iterativeConstexprFact == recursiveConstexprFact
    );

    assert (runtimeRes == templateFact);

    return std::tuple<int, int>{arg, runtimeRes};
}