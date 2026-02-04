#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t K;
size_t i;

void init_vars() {
    // Estimate iteration count for ~0.01 seconds
    // Assume a modern CPU can do roughly 3e9 cycles per second
    // Aim for about 30 million iterations as baseline for simple loop
    K = 30000000; // 30 million iterations should take ~0.01s on many systems
}