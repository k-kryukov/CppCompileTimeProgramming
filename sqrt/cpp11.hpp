#include <stdexcept>
#include <cassert>
#include "runtimeSqrt.hpp"
#include <type_traits>

namespace cpp11 {

    // template Sqrt
    template<int x, int i = 0, typename = typename std::enable_if<x >= 0>::type>
    struct structSqrt
        : std::integral_constant<int,
                typename std::conditional<
                    (i * i <= x),
                    structSqrt<x, i + 1>,
                    std::integral_constant<int, i - 1>
                >::type{}
            >
    {};

    // does not work
    template<int x, int i = 0, typename = typename std::enable_if<x >= 0>::type>
    struct anotherStructSqrt {
        static const int value = std::integral_constant<int,
            typename std::conditional<
                (i * i <= x),
                std::integral_constant<int, anotherStructSqrt<x, i + 1>::value>,
                std::integral_constant<int, i - 1>
            >::type{}
        >{};
    };
}

void sampleTests() {
    static_assert(cpp11::structSqrt<1>{} == 1);
    static_assert(cpp11::structSqrt<4>{} == 2);
    static_assert(cpp11::structSqrt<3>{} == 1);
    static_assert(cpp11::structSqrt<255>{} == 15);
    static_assert(cpp11::structSqrt<256>{} == 16);
    static_assert(cpp11::structSqrt<0>{} == 0);

    // static_assert(cpp11::structSqrt<-1>{} == :( );
}

inline std::pair<int, int> testCpp11(){
    sampleTests();

    const int arg = 257;

    auto runtimeRes = ::runtimeSqrt(arg);
    constexpr int structSqrtRes1 = cpp11::structSqrt<arg>{};
    // constexpr int structSqrtRes2 = cpp11::anotherStructSqrt<arg>::value;

    // static_assert(structSqrtRes1 == structSqrtRes2);

    assert(structSqrtRes1 == runtimeRes);

    return {arg, runtimeRes};
}
