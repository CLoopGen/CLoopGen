#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
float alpha = 1.5f;

float *X;
int incX = 1;

float *Y;
int incY = 1;

float *A;
int lda = 1024;

int i;
int j;
int ix = 0;
int iy = 0;

void init_vars() {
    X = (float*)aligned_alloc(32, N * incX * sizeof(float));
    Y = (float*)aligned_alloc(32, N * incY * sizeof(float));
    A = (float*)aligned_alloc(32, N * lda * sizeof(float));

    for (int k = 0; k < N * incX; k++) {
        X[k] = 1.0f + k * 0.1f;
    }
    for (int k = 0; k < N * incY; k++) {
        Y[k] = 2.0f + k * 0.2f;
    }
    for (int k = 0; k < N * lda; k++) {
        A[k] = 0.5f;
    }
}