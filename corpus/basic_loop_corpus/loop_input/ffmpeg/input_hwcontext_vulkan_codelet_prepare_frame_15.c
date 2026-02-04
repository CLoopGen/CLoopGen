#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int planes;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assuming a modern CPU can do ~1e9 iterations per second,
    // 1e7 iterations should take ~0.01 seconds.
    planes = 10000000; // 10 million planes
}