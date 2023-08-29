#include <stdexcept>
#include <cassert>
#include "runtimeFactorial.hpp"

namespace cpp11 {

    // template factorial
    template<int x, typename = typename std::enable_if<(x >= 0)>::type>
    struct structFactorial {
        static const int value = x * structFactorial<x - 1>::value;
    };

    template<>
    struct structFactorial<0> {
        static const int value = 1;
    };

    // constexpr factorial
    constexpr int constexprFactorial(int x) {
        return (x > 0
                ? x * constexprFactorial(x - 1)
                : x == 0 ? 1
                : throw std::runtime_error{"Factorial argument must be non-negative"}
        );
    }
}

inline std::pair<int, int> testCpp11(){
    const int arg = 5;

    auto runtimeRes = ::runtimeFactorial(arg);
    constexpr auto templateFact = cpp11::structFactorial<arg>::value;
    constexpr auto constexprFact = cpp11::constexprFactorial(arg);

    // constexpr auto badCall1 = cpp11::structFactorial<-1>::value;
    // constexpr auto badCall2 = cpp11::constexprFactorial(-1);

    static_assert(templateFact == constexprFact);

    assert (runtimeRes == templateFact && templateFact == constexprFact);

    return {arg, runtimeRes};
}