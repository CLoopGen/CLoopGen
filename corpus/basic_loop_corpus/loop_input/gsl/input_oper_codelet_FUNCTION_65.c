#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t loop_lim;
size_t i;

void init_vars() {
    // Estimate loop limit to achieve ~0.01 seconds runtime
    // Assume a modern CPU can do ~1e9 operations/sec -> ~1e7 per 0.01 sec
    // Since the loop body is empty, we need to scale based on expected timing overhead.
    // Use 10 million iterations as a reasonable default to hit ~0.01 sec including loop overhead.

    loop_lim = 10000000;  // 10^7 iterations
}