#include <iostream>
#include <tuple>

#ifdef CPP11
#include "cpp11.hpp"
#endif

#ifdef CPP14
#include "cpp14.hpp"
#endif

#ifdef CPP20
#include "cpp20.hpp"
#endif

int main() {
    #ifdef CPP11
    int arg, res;
    std::tie(arg, res) = testCpp11();
    std::cout << "C++11: integer sqrt(" << arg << ") = " << res << std::endl;
    #endif

    #ifdef CPP14
    int arg, result;
    std::tie(arg, result) = testCpp14();
    std::cout << "C++14: " << arg << "! = " << result << std::endl;
    #endif

    #ifdef CPP17
    // nothing to show here except structured bindings
    #endif

    #ifdef CPP20
    auto [arg, result] = testCpp20();
    std::cout << "C++20: " << arg << "! = " << result << std::endl;
    #endif

    return 0;
}