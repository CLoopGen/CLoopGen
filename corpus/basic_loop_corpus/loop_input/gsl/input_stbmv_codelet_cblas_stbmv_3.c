#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
int K = 128;
float *A;
int lda = 512;
float *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix = 0;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * lda * N);
    X = (float*)aligned_alloc(32, sizeof(float) * (N * abs(incX) + K + 1));

    for (int idx = 0; idx < lda * N; idx++) {
        A[idx] = 1.0f / (idx % 100 + 1);
    }
    for (int idx = 0; idx < N * abs(incX) + K + 1; idx++) {
        X[idx] = (idx % 7) * 0.1f;
    }
}