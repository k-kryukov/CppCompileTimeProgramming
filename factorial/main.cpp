#include <iostream>

#ifdef CPP11
#include "cpp11.hpp"
#endif

#ifdef CPP14
#include "cpp14.hpp"
#endif

#ifdef CPP17
#include "cpp17.hpp"
#endif

int main() {
    #ifdef CPP11
    auto pair = testCpp11();
    std::cout << pair.first << "! = " << pair.second << std::endl;
    #endif

    #ifdef CPP14
    int arg, result;
    std::tie(arg, result) = testCpp14();
    std::cout << arg << "! = " << result << std::endl;
    #endif

    #ifdef CPP17
    testCpp17();
    #endif

    #ifdef CPP20
    testCpp20();
    #endif

    return 0;
}