#include <tuple>
#include <stdexcept>
#include "runtimeFactorial.hpp"
#include <cassert>

namespace cpp20 {
    template<int x>
    concept NonNegative = requires() { requires(x >= 0); };

    template<int x> requires NonNegative<x> // requires (x >= 0)
    struct structFactorial {
        static const int value = x * structFactorial<x - 1>::value;
    };

    template<>
    struct structFactorial<0> {
        static const int value = 1;
    };

    consteval int constevalFactorial(int x) {
        // throw idiom
        if (x < 0)
            throw std::runtime_error{"Factorial argument must be non-negative"};
        if (x == 0)
            return 1;

        return x * constevalFactorial(x - 1);
    }

    #ifdef CPP23 // not sure this implementation is very useful
    constexpr int universalFactorial(int x) {
        if consteval {
            return constevalFactorial(x);
        }
        else {
            return runtimeFactorial(x);
        }
    }
    #endif
};

auto testCpp20() {
    const int arg = 5;

    auto runtimeRes = ::runtimeFactorial(arg);
    constexpr auto templateFact = cpp20::structFactorial<arg>::value;
    constexpr auto constexprFact = cpp20::constevalFactorial(arg);

    // constexpr auto badCall1 = cpp20::structFactorial<-1>::value;
    // constexpr auto badCall2 = cpp20::constevalFactorial(-1);

    static_assert(
        templateFact == constexprFact
    );

    assert (runtimeRes == templateFact && templateFact == constexprFact);

    return std::tuple{arg, runtimeRes};
}