#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float beta;
float *Y;
int incY;
int i;
int iy;

void init_vars() {
    N = 1 << 20; // 1 million elements for ~1MB of float data (4 bytes per float)
    beta = 1.5f;
    incY = 1;
    iy = 0;

    Y = (float *)aligned_alloc(32, N * sizeof(float));
    if (!Y) {
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        Y[j] = (float)(j + 1);
    }
}