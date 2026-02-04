#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1 << 20; // 1 million elements for ~0.01 sec runtime

float *X;
int incX;
float *Y;
int incY;
int i;
int ix;
int iy;

void init_vars() {
    X = (float *)aligned_alloc(32, N * sizeof(float));
    Y = (float *)aligned_alloc(32, N * sizeof(float));

    if (!X || !Y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = 1.0f + j;
        Y[j] = 2.0f + j;
    }

    incX = 1;
    incY = 1;
    ix = 0;
    iy = 0;
}