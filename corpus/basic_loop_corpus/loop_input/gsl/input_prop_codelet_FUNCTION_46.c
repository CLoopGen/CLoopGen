#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming typical modern CPU can handle nested loops with ~10^7 to 10^8 iterations in about 0.01s
    // We choose sizes such that total iterations ≈ 100 million (10^8)
    size1 = 10000;
    size2 = 10000;
}