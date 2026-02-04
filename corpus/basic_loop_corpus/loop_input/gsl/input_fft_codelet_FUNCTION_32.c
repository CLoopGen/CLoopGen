#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t k1;
size_t product_1;

void init_vars() {
    // Initialize product_1 to a value that makes the loop run for approximately 0.01 seconds
    // Assuming a modern CPU can handle around 1e9 iterations per second,
    // 10 million iterations should take about 0.01 seconds.
    product_1 = 10000000;  // 10^7 iterations
}

// Note: k1 is modified in the loop, so no initial value needed beyond zero initialization