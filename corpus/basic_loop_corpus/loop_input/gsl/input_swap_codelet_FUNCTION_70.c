#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming a data size that would make the loop run approximately 0.01 seconds
    // A simple loop with no memory operations: aim for ~10-100 million iterations
    size1 = 50000000;  // 50 million iterations should be around 0.01s on modern CPUs
}