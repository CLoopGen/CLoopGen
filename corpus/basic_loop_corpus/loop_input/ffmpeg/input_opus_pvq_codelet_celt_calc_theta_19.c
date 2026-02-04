#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
float *Y;
int N;
int i;
float e[2];

void init_vars() {
    N = 134217728; // Approximately 512MB of data (2 arrays of float, 4 bytes each)

    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    if (!X || !Y) {
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = 1.0f + (j % 100) * 0.01f;
        Y[j] = 2.0f + (j % 100) * 0.02f;
    }

    e[0] = 0.0f;
    e[1] = 0.0f;
}