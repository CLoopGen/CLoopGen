#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
float *Y;
int N;
int i;

void init_vars() {
    N = 1 << 20; // Approximately 4 million elements, ~16MB per array

    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    for (int j = 0; j < N; j++) {
        X[j] = 1.0f + j * 0.0001f;
        Y[j] = 0.5f - j * 0.00005f;
    }
}