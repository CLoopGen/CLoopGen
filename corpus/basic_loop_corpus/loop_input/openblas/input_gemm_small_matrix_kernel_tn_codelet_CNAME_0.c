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
float beta = 0.5f;
float *C;
BLASLONG ldc = 200;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float result;

void init_vars() {
    A = (float*)calloc(M * K, sizeof(float));
    B = (float*)calloc(K * N, sizeof(float));
    C = (float*)calloc(M * N, sizeof(float));

    for (BLASLONG idx = 0; idx < M * K; idx++) {
        A[idx] = (float)(idx % 100) / 100.0f;
    }
    for (BLASLONG idx = 0; idx < K * N; idx++) {
        B[idx] = (float)(idx % 100) / 100.0f;
    }
    for (BLASLONG idx = 0; idx < M * N; idx++) {
        C[idx] = (float)(idx % 100) / 100.0f;
    }
}