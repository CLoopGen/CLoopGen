#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 256;
float alpha = 1.5f;
float *A;
int lda = 512;
float *C;
int ldc = 512;
int i;
int j;
int k;

void init_vars() {
    A = (float*)aligned_alloc(32, 2 * K * lda * sizeof(float));
    C = (float*)aligned_alloc(32, 2 * N * ldc * sizeof(float));

    for (int idx = 0; idx < 2 * K * lda; idx++) {
        A[idx] = (float)(idx % 127) / 127.0f;
    }

    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        C[idx] = (float)(idx % 251) / 251.0f;
    }
}