#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int len;
double *x;
int i;
double sum;

void init_vars() {
    // Target approximately 0.01 seconds runtime
    // Estimate: simple loop with absolute value, ~1-2 cycles per element on modern CPU
    // At 3 GHz, 0.01 s = ~30e9 cycles -> aim for ~15e6 to 30e6 elements for safety
    // Use 20 million elements (~160 MB for doubles) as a reasonable midpoint

    len = 20000000;  // 20 million elements
    x = (double*)aligned_alloc(32, len * sizeof(double));
    if (!x) {
        exit(1);
    }

    // Initialize x with random values centered around zero to ensure some negatives
    srand((unsigned int)time(NULL));
    for (int j = 0; j < len; j++) {
        // Random double in [-1000, 1000)
        x[j] = ((double)rand() / RAND_MAX) * 2000.0 - 1000.0;
    }

    // Initialize loop counters
    i = 0;
    sum = 0.0;
}