#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t size1;
size_t p;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume simple loop overhead; adjust size1 to get desired compute time
    // A size of around 10 million iterations typically takes ~0.01s on modern CPUs

    size1 = 10000000;  // 10^7 iterations, reasonable for ~10ms in a simple loop
}