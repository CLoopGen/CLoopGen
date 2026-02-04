#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG M = 256;
BLASLONG N = 256;
BLASLONG K = 256;

float *A;
BLASLONG lda = 256;
float alpha = 1.5f;
float *B;
BLASLONG ldb = 256;
float beta = 0.5f;
float *C;
BLASLONG ldc = 256;

BLASLONG i;
BLASLONG j;
BLASLONG k;
float result;

void init_vars() {
    A = (float*)malloc(M * K * sizeof(float));
    B = (float*)malloc(K * N * sizeof(float));
    C = (float*)malloc(M * N * sizeof(float));

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