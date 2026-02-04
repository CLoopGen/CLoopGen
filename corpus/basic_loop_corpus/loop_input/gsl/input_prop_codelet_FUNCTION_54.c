#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop is intended to process a 2D array with ~64 million elements
    // for a runtime around 0.01 seconds on modern CPUs.
    size1 = 8192;
    size2 = 8192;
}