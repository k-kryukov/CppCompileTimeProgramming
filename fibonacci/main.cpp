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
    std::cout << "Fibonacci number [" << arg << "] = " << res << std::endl;
    #endif

    #ifdef CPP14
    // nothing to show here except std::enable_if_t
    #endif

    #ifdef CPP17
    // nothing to show here except structured bindings
    #endif

    #ifdef CPP20
    auto [arg, res] = testCpp20();
    std::cout << "Fibonacci number [" << arg << "] = " << res << std::endl;
    #endif

    return 0;
}