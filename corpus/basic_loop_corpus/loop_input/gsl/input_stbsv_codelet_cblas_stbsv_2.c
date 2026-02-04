#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
int K = 64;
float *A;
int lda;
float *X;
int incX;
int nonunit;

int i;
int j;
int ix;

void init_vars() {
    lda = N;
    incX = 1;
    nonunit = 1;
    i = 0;
    j = 0;
    ix = 0;

    A = (float*)aligned_alloc(32, sizeof(float) * N * lda);
    X = (float*)aligned_alloc(32, sizeof(float) * N);

    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = 1.0f + (idx % (K + 1) <= idx / lda ? 0.1f : 0.0f);
    }

    for (int idx = 0; idx < N; idx++) {
        X[idx] = 2.0f;
    }
}