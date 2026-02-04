#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

int M = 512;
int N = 512;
float alpha = 1.5f;
float *X;
int incX = 1;
float *Y;
int incY = 1;
float *A;
int lda = 512;
int i;
int j;
int jy;

void init_vars() {
    X = (float*)aligned_alloc(32, M * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));
    A = (float*)aligned_alloc(32, M * N * sizeof(float));

    for (int idx = 0; idx < M; idx++) {
        X[idx] = (float)(idx % 128) * 0.01f;
    }
    for (int idx = 0; idx < N; idx++) {
        Y[idx] = (float)(idx % 128) * 0.02f;
    }
    for (int idx = 0; idx < M * N; idx++) {
        A[idx] = (float)(idx % 256) * 0.005f;
    }

    jy = 0;
}