#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
float *Y;
int N;
int i;

void init_vars() {
    N = 67108864; // Approximately 256 MB of data (67M elements * 4 bytes per float * 2 arrays)

    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    if (!X || !Y) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = (float)(j % 1000) + 1.0f;
        Y[j] = 0.0f;
    }
}