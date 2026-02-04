#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float *X;
int incX;
float *Y;
int incY;
int i;
int ix;
int iy;

void init_vars() {
    N = 1 << 20; // Approximately 4 million elements, ~16 MB per array

    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    if (!X || !Y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = (float)(j * 2 + 1);
        Y[j] = 0.0f;
    }

    incX = 1;
    incY = 1;
    ix = 0;
    iy = 0;
}