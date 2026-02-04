#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int K = 256;
float alpha = 1.5f;

float *A;
int lda = 256;
float *B;
int ldb = 256;
float *C;
int ldc = 1024;

int i;
int j;
int k;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * N * lda);
    B = (float*)aligned_alloc(32, sizeof(float) * N * ldb);
    C = (float*)aligned_alloc(32, sizeof(float) * N * ldc);

    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = (float)(idx % 128) * 0.01f;
    }

    for (int idx = 0; idx < N * ldb; idx++) {
        B[idx] = (float)(idx % 128) * 0.02f;
    }

    for (int idx = 0; idx < N * ldc; idx++) {
        C[idx] = (float)(idx % 256) * 0.005f;
    }
}