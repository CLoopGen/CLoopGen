#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
float beta = 1.5f;
int ldc = 2048;

float *C;

int i;
int j;

void init_vars() {
    C = (float*)aligned_alloc(32, N * ldc * sizeof(float));
    if (!C) {
        exit(1);
    }
    for (int idx = 0; idx < N * ldc; ++idx) {
        C[idx] = (float)(idx % 100) / 10.0f;
    }
}