#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N;
float alpha;
float *X;
int incX;
float *Y;
int incY;
float *A;
int lda;
int i;
int j;
int ix;
int iy;

void init_vars() {
    N = 1024;
    alpha = 1.5f;
    incX = 1;
    incY = 1;
    lda = N;

    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));
    A = (float*)aligned_alloc(32, N * N * sizeof(float));

    for (int k = 0; k < N; k++) {
        X[k] = (float)(k % 128) * 0.01f;
        Y[k] = (float)((k + 10) % 128) * 0.01f;
    }

    for (int k = 0; k < N * N; k++) {
        A[k] = 0.0f;
    }

    i = 0;
    j = 0;
    ix = 0;
    iy = 0;
}