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
    // On a typical modern CPU, an empty loop overhead is low.
    // To achieve measurable time, set K to about 100 million iterations.
    K = 100000000; // 100 million iterations typically takes ~0.01s on many systems
}