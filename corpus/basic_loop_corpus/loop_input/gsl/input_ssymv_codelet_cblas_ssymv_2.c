#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
float alpha = 1.5f;

float *A;
int lda;

float *X;
int incX = 1;

float *Y;
int incY = 1;

int i;
int j;
int ix = 0;
int iy = 0;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * N * N);
    X = (float*)aligned_alloc(32, sizeof(float) * N);
    Y = (float*)aligned_alloc(32, sizeof(float) * N);

    for (int idx = 0; idx < N; ++idx) {
        X[idx] = 1.0f + idx * 0.01f;
        Y[idx] = 2.0f + idx * 0.02f;
    }

    for (int idx = 0; idx < N * N; ++idx) {
        A[idx] = 0.01f + 0.001f * (idx % 100);
    }

    lda = N;
    ix = 0;
    iy = 0;
}