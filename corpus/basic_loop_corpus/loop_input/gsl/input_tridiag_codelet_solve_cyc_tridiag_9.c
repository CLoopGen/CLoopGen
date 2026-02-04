#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t N;
double *delta;
double *z;
size_t i;
double sum;

void init_vars() {
    N = 20000000;  // Approximately 20 million elements for ~0.01 sec runtime

    delta = (double *)aligned_alloc(32, N * sizeof(double));
    z = (double *)aligned_alloc(32, N * sizeof(double));

    if (!delta || !z) {
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 0; idx < N; idx++) {
        delta[idx] = (double)(idx % 1000) / 100.0;
        z[idx] = (double)((idx + 5) % 970) / 97.0;
    }

    i = 0;
    sum = 0.0;
}