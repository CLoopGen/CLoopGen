#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *restrict iy;
float *restrict X;
int N;
float g;
int i;

void init_vars() {
    N = 1 << 20; // Approximately 4MB of float data (about 1M elements)
    g = 2.5f;

    iy = (int*)aligned_alloc(32, N * sizeof(int));
    X = (float*)aligned_alloc(32, N * sizeof(float));

    for (int j = 0; j < N; j++) {
        iy[j] = j % 100;
        X[j] = 0.0f;
    }
}