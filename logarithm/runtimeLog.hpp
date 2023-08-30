#include <stdexcept>

inline int runtimeLog(int x) {
    if (x <= 0)
        throw std::runtime_error{"Logarithm arg must be positive!"};

    unsigned cnt = 0;
    while (x > 1) {
        x >>= 1; ++cnt;
    }

    return cnt;
}