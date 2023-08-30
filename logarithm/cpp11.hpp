#include <type_traits>

namespace cpp11 {
    template<int x, typename = typename std::enable_if<x >= 1>::type>
    struct structLog {
        static const auto value = structLog<x / 2>::value + 1;
    };

    template<>
    struct structLog<1> {
        static const auto value = 0;
    };

    constexpr int constexprFuncLog(int x) {
        return (x > 1) ? 1 + constexprFuncLog(x / 2) :
                (x == 1) ? 0 :
                throw std::runtime_error{"Logarithm arg must be positive!"};

    }
}

std::pair<int, int> testCpp11() {
    const int arg = 1 << 20;

    constexpr auto res = cpp11::structLog<arg>::value;
    constexpr auto templateRes = cpp11::constexprFuncLog(arg);

    static_assert(res == templateRes);

    // constexpr auto badCall1 = cpp14::structLog<-1>::value;

    return {arg, res};
}