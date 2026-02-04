#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int len;
double *x;
int i;
double invnorm;
double sum;
double tmp;

void init_vars() {
    // Target approximately 0.01 seconds runtime
    // Estimate: simple loop with a few floating point ops per iteration
    // Assume ~1e9 operations per second, so aim for ~1e7 iterations for 0.01s
    // Use 16 million elements to ensure measurable time even with optimizations
    len = 16000000;

    x = (double*)aligned_alloc(32, len * sizeof(double));
    if (!x) {
        exit(1);
    }

    invnorm = 1.0 / sqrt(len);  // arbitrary normalization factor
    sum = 0.0;

    // Initialize x with non-zero values to avoid degenerate cases
    for (int j = 0; j < len; j++) {
        x[j] = (double)(j % 1000) + 1.0;
    }
}