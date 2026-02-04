#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t src_size1;
size_t i;

void init_vars() {
    // Assuming a typical modern CPU can handle roughly 1e8 operations per second
    // To make the loop run for approximately 0.01 seconds, we set the size to about 1e6 iterations
    src_size1 = 1000000; // 1 million elements for ~0.01 sec runtime
}