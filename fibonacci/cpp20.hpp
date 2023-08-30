#include <stdexcept>
#include <cassert>
#include <utility>

#include "runtimeFibonacci.hpp"

namespace cpp20 {
    template<unsigned n> requires (n >= 0)
    struct structFibonacci {
        static const auto value = structFibonacci<n - 1>::value + structFibonacci<n - 2>::value;
    };

    template<>
    struct structFibonacci<1> {
        static const auto value = 1;
    };

    template<>
    struct structFibonacci<0> {
        static const auto value = 0;
    };

    constexpr int getFibonacci(int n) {
        if (n < 0)
            throw std::runtime_error{"Negative fibonacci number index is not supported!"};
        if (n <= 1)
            return n;

        int a = 0, b = 1;
        for (int i = 2; i <= n; i++)
            a = std::exchange(b, a + b);

        return b;
    }
}

inline std::pair<int, int> testCpp20(){
    const unsigned arg = 10;

    auto runtimeRes = ::runtimeFibonacci(arg);
    constexpr auto templateFibonacci = cpp20::structFibonacci<arg>::value;
    constexpr auto constexprFuncFibonacci = cpp20::getFibonacci(arg);

    // constexpr auto badCall1 = cpp20::structFibonacci<-1>::value;
    // constexpr auto badCall2 = cpp20::getFibonacci(-1);

    static_assert(templateFibonacci == constexprFuncFibonacci);

    assert (runtimeRes == templateFibonacci);

    return {arg, runtimeRes};
}