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
    // On a typical modern CPU, a simple loop with minimal work per iteration
    // can execute about 1e9 iterations per second. So for 0.01s, aim for ~1e7 iterations.
    M = 10000000;  // 10 million iterations should take ~0.01 seconds
}