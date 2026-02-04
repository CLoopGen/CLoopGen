#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N;
float alpha;
float *X;
int incX;
float *A;
int lda;
int i;
int j;
int ix;

void init_vars() {
    N = 2048;
    alpha = 1.5f;
    incX = 1;
    lda = N;
    ix = 0;

    X = (float*)aligned_alloc(32, N * sizeof(float));
    A = (float*)aligned_alloc(32, N * lda * sizeof(float));

    for (int k = 0; k < N; k++) {
        X[k] = (float)(k % 128) * 0.1f;
    }

    for (int k = 0; k < N * lda; k++) {
        A[k] = 0.0f;
    }
}