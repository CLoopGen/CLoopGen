#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming a typical modern CPU can handle ~1e8 operations per second,
    // set size1 to ensure loop runs for approximately 0.01 seconds
    // We assume the loop body has minimal work, so data size drives runtime.
    // Aim for about 10 million iterations to target ~0.01s based on typical performance.

    size1 = 10000000;  // 10 million iterations
}