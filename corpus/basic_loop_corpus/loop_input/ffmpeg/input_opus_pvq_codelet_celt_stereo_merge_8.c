#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
float *Y;
int N;
int i;
float xp;
float side;

void init_vars() {
    N = 1 << 20; // Approximately 4 million elements, ~16MB per array

    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    for (int j = 0; j < N; j++) {
        X[j] = (float)(j % 100) * 0.01f;
        Y[j] = (float)((j + 10) % 75) * 0.02f;
    }

    xp = 0.0f;
    side = 0.0f;
}