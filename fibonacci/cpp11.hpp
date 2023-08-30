#include <stdexcept>
#include <cassert>
#include "runtimeFibonacci.hpp"

namespace cpp11 {

    template<unsigned n, typename = typename std::enable_if<n >= 0>::type>
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
}

inline std::pair<int, int> testCpp11(){
    const unsigned arg = 10;

    auto runtimeRes = ::runtimeFibonacci(arg);
    constexpr auto templateFibonacci = cpp11::structFibonacci<arg>::value;

    assert (runtimeRes == templateFibonacci);

    return {arg, runtimeRes};
}