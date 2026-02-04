#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

size_t N;
double *alpha;
double *c;
double *z;
size_t i;

void init_vars() {
    N = 16777216; // 16M elements, ~128MB total data (4 arrays × 8 bytes per double)

    alpha = (double*)aligned_alloc(32, N * sizeof(double));
    c = (double*)aligned_alloc(32, N * sizeof(double));
    z = (double*)aligned_alloc(32, N * sizeof(double));

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < N; idx++) {
        alpha[idx] = (double)(rand() % 100 + 1); // Ensure non-zero
        z[idx] = (double)(rand() % 1000);
        c[idx] = 0.0;
    }
}