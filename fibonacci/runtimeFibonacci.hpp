#include <stdexcept>

int runtimeFibonacci(int n) {
    if (n < 0)
        throw std::runtime_error{"Negative fibonacci number index is not supported!"};
    if (n <= 1)
        return n;

    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        b += a;
        a = (b - a);
    }

    return b;
}