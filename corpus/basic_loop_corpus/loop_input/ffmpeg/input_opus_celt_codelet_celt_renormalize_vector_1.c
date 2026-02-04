#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *X;
int N = 1 << 24; // ~16.7 million elements, ~64 MB of data
int i;
float g;

void init_vars() {
    X = (float*)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((unsigned int)ts.tv_nsec);

    for (int j = 0; j < N; j++) {
        X[j] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f; // Random float in [-1, 1]
    }

    g = 0.0f;
}