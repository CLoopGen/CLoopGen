#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t M;
size_t i;

void init_vars() {
    // Estimate iterations to achieve ~0.01 seconds runtime
    // The loop body is very light (just declare a variable), so we need a large iteration count
    // On a modern CPU, a simple loop like this might run ~1e9 iterations per second
    // So for 0.01 seconds, use ~10 million iterations
    M = 10000000;  // 10^7 iterations ≈ 0.01 sec
}