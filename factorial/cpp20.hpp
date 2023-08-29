#include <tuple>
#include <stdexcept>
#include "runtimeFactorial.hpp"
#include <cassert>

namespace cpp20 {
    template<int x>
    concept NonNegative = requires() { requires(x >= 0); };

    // might be just simple requires(x >= 0)
    template<int x> requires NonNegative<x>
    struct structFactorial {
        static const int value = x * structFactorial<x - 1>::value;
    };

    template<>
    struct structFactorial<0> {
        static const int value = 1;
    };

    consteval int constexprFactorial(int x) {
        // throw idiomrun-cpp11
        if (x < 0)
            throw std::runtime_error{"Factorial argument must be non-negative"};
        if (x == 0)
            return 1;

        return x * constexprFactorial(x - 1);
    }
};

auto testCpp20() {
    const int arg = 5;

    auto runtimeRes = ::runtimeFactorial(arg);
    constexpr auto templateFact = cpp20::structFactorial<arg>::value;
    constexpr auto constexprFact = cpp20::constexprFactorial(arg);

    // constexpr auto badCall = cpp20::structFactorial<-1>::value;

    static_assert(
        templateFact == constexprFact
    );

    assert (runtimeRes == templateFact && templateFact == constexprFact);

    return std::tuple{arg, runtimeRes};
}