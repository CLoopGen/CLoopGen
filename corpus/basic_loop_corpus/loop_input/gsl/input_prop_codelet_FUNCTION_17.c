#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming typical modern CPU can handle ~1e8 iterations per second
    // We want loop to run for ~0.01 seconds -> ~1e6 total iterations
    // Set sizes such that size1 * size2 ≈ 1e6
    size1 = 1000;
    size2 = 1000;
}