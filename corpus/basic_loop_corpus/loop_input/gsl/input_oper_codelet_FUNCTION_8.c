#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t loop_lim;
size_t i;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume a modern CPU can do ~1e9 operations/sec -> ~1e7 operations in 0.01s
    // Since the loop body is empty, we scale input size to ensure measurable duration
    // Use 16 million iterations as baseline for light-weight loop
    loop_lim = 16000000;  // 16e6 iterations should take ~0.01s on average
}