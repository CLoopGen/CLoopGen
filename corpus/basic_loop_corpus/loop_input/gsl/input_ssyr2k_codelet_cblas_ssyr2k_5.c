#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N = 512;
int K = 128;
float alpha = 1.3f;

float *A;
int lda = 512;
float *B;
int ldb = 512;
float *C;

int i, j, k;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * lda * K);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * K);
    C = (float*)aligned_alloc(32, sizeof(float) * N * N);

    for (int idx = 0; idx < lda * K; idx++) {
        A[idx] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }

    for (int idx = 0; idx < ldb * K; idx++) {
        B[idx] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }

    for (int idx = 0; idx < N * N; idx++) {
        C[idx] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }
}