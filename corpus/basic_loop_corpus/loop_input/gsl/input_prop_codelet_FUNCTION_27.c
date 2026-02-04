#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Estimate loop overhead to achieve ~0.01 seconds runtime
    // Assume a typical modern CPU can perform roughly 1e9 iterations per second
    // Target: ~10 million total iterations for the inner loop to take ~0.01 seconds

    size1 = 3000;
    size2 = 3000;
}