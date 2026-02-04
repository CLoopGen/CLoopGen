#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG M = 200;
BLASLONG N = 200;
BLASLONG K = 200;
float *A;
BLASLONG lda = 200;
float alpha = 1.5f;
float *B;
BLASLONG ldb = 200;
float beta = 0.8f;
float *C;
BLASLONG ldc = 200;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float result;

void init_vars() {
    A = (float*)aligned_alloc(32, M * K * sizeof(float));
    B = (float*)aligned_alloc(32, K * N * sizeof(float));
    C = (float*)aligned_alloc(32, M * N * sizeof(float));

    for (BLASLONG idx = 0; idx < M * K; idx++) {
        A[idx] = (float)(idx % 128) / 64.0f;
    }

    for (BLASLONG idx = 0; idx < K * N; idx++) {
        B[idx] = (float)(idx % 128) / 64.0f;
    }

    for (BLASLONG idx = 0; idx < M * N; idx++) {
        C[idx] = (float)(idx % 128) / 32.0f;
    }
}