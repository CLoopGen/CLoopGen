#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float beta;
float *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 4096;
    beta = 1.5f;
    ldc = N;
    C = (float*)aligned_alloc(32, sizeof(float) * N * ldc);
    if (!C) {
        exit(1);
    }
    for (int idx = 0; idx < N * ldc; idx++) {
        C[idx] = (float)(idx % 100);
    }
}