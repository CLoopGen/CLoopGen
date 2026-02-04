#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 64;
float alpha = 1.5f;

float *A;
int lda = 512;
float *B;
int ldb = 512;
float *C;
int i, j, k;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * K * lda);
    B = (float*)aligned_alloc(32, sizeof(float) * K * ldb);
    C = (float*)aligned_alloc(32, sizeof(float) * N * lda);

    for (int idx = 0; idx < K * lda; idx++) {
        A[idx] = (float)(idx % 128) * 0.01f;
    }

    for (int idx = 0; idx < K * ldb; idx++) {
        B[idx] = (float)(idx % 128) * 0.02f;
    }

    for (int idx = 0; idx < N * lda; idx++) {
        C[idx] = (float)(idx % 256) * 0.005f;
    }
}