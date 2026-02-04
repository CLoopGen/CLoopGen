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
    N = 1 << 20; // 1 million elements for ~0.01 sec runtime
    beta = 1.5f;
    incY = 1;
    iy = 0;

    Y = (float *)aligned_alloc(32, N * sizeof(float));
    if (!Y) {
        exit(1);
    }

    for (int idx = 0; idx < N; idx++) {
        Y[idx] = (float)(idx % 100);
    }
}