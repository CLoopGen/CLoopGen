#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming a data size that would make the loop run approximately 0.01 seconds
    // A modern CPU can do billions of operations per second, so a few million iterations might take ~0.01s
    // We choose size1 such that the loop runs enough times to reach this target
    size1 = 10000000;  // 10 million iterations should be safe for ~0.01s on most systems
}