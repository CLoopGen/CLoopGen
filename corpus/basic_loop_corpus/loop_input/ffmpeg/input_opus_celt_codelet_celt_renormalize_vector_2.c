#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
int N;
int i;
float g;

void init_vars() {
    N = 1 << 22; // Approximately 16 million elements (64 MB for float)
    X = (float*)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        X[j] = 1.5f + j * 0.0001f;
    }
    g = 2.5f;
    i = 0;
}