#include <stdexcept>

int runtimeSqrt(int x) {
    if (x < 0)
        throw std::runtime_error{"Sqrt is not implemented for negative numbers"};

    unsigned i = 0;
    while (i * i <= x) {
        ++i;
    }

    return i - 1;
}