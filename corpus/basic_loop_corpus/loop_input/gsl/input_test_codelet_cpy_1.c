#include <stdlib.h>
#include <stdio.h>

double *dest;
double *src;
size_t N;
size_t i;

void init_vars() {
    N = 16777216; // 128 MB of data (16M * 8 bytes per double)

    src = (double*)aligned_alloc(32, N * sizeof(double));
    dest = (double*)aligned_alloc(32, N * sizeof(double));

    if (!src || !dest) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < N; idx++) {
        src[idx] = (double)(idx & 0xFF);
    }

    i = 0;
}