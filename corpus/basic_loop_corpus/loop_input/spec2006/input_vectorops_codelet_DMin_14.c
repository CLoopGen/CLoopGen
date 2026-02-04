#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

double *vec;
int n = 1 << 24; // Approximately 128 MB of data (16M * 8 bytes per double)
int i;
double best;

void init_vars() {
    vec = (double*)aligned_alloc(32, n * sizeof(double));
    if (!vec) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Seed random number generator and initialize vector
    srand(time(NULL));
    for (int j = 0; j < n; j++) {
        vec[j] = (double)(rand() % 10000) / 10.0;
    }

    // Initialize best to first element to ensure correctness and avoid out-of-bounds
    best = vec[0];
    i = 1; // Loop starts at i = 1
}