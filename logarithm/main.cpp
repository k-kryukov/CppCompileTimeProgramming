#include <iostream>

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
    auto pair = testCpp11();
    std::cout << "C++11 logarithm: arg = " << pair.first << ", result = " << pair.second << std::endl;
    #endif

    #ifdef CPP14
    int arg, result;
    std::tie(arg, result) = testCpp14();
    std::cout << "C++14 logarithm: arg = " << arg << ", result = " << result << std::endl;
    #endif

    #ifdef CPP17
    // nothing to show here except structured bindings
    #endif

    #ifdef CPP20
    auto [arg, result] = testCpp20();
    std::cout << "C++20 logarithm: arg = " << arg << ", result = " << result << std::endl;
    #endif

    return 0;
}