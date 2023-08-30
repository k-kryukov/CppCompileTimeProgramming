#include <stdexcept>
#include <tuple>
#include <cassert>
#include "runtimeLog.hpp"

namespace cpp14 {
    template<int x, typename = std::enable_if_t<x >= 1>>
    struct structLog {
        static const auto value = structLog<x / 2>::value + 1;
    };

    template<>
    struct structLog<1> {
        static const auto value = 0;
    };

    constexpr int constexprFuncLog(int x) {
        if (x <= 0)
            throw std::runtime_error{"Logarithm arg must be positive!"};
        unsigned cnt = 0;

        while (x > 1) {
            x >>= 1; ++cnt;
        }

        return cnt;
    }

}

auto testCpp14() {
    const int arg = 1 << 20;

    constexpr auto res = cpp14::constexprFuncLog(arg);
    constexpr auto templateRes = cpp14::structLog<arg>::value;
    auto runtimeRes = ::runtimeLog(arg);

    // constexpr auto badCall1 = cpp14::structLog<-1>::value;
    // constexpr auto badCall2 = cpp14::constexprFuncLog(-1);

    static_assert(res == templateRes);

    assert(runtimeRes == res);

    return std::tuple<int, int>{arg, res};
}