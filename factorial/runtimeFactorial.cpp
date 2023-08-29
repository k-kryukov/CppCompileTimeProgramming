#include "runtimeFactorial.hpp"

int runtimeFactorial(int x) {
    if (x < 0)
        throw std::runtime_error{"Factorial argument must be non-negative"};
    if (x == 0) return 1;

    return x * runtimeFactorial(x - 1);
}