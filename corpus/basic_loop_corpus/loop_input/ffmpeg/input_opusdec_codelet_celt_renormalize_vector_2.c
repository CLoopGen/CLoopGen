#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
int N;
int i;
float g;

void init_vars() {
    N = 1 << 20; // 1 million elements, ~4MB for float array
    X = (float*)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        X[j] = 1.0f + (j % 100);
    }
    g = 1.5f;
    i = 0;
}