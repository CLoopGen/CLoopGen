#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
float alpha = 1.5f;
float *X;
int incX = 1;
float *A;
int lda = 2048;
int i;
int j;
int ix = 0;

void init_vars() {
    X = (float*)aligned_alloc(32, N * incX * sizeof(float));
    A = (float*)aligned_alloc(32, N * lda * sizeof(float));

    for (int k = 0; k < N * incX; k++) {
        X[k] = (float)(k % 123) * 0.1f;
    }

    for (int k = 0; k < N * lda; k++) {
        A[k] = (float)(k % 456) * 0.01f;
    }
}