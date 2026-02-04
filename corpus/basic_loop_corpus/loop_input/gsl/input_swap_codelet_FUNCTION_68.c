#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t K;
size_t i;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume modern CPU can handle roughly 1e9 iterations per second
    // So for 0.01 seconds, use 10 million iterations
    K = 10000000;  // 10^7 iterations
}