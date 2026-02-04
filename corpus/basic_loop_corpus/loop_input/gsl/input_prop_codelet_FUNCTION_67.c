#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop is empty, we choose sizes to make the loop run approximately 0.01 seconds
    // On a typical modern CPU, an empty double loop overhead depends on iteration count.
    // We estimate that around 100 million iterations (1e8) may take ~0.01 seconds

    size1 = 10000;  // Outer loop
    size2 = 10000;  // Inner loop => total 100e6 iterations
}