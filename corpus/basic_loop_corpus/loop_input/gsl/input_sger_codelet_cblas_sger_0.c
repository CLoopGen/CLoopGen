#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int M = 1024;
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

void init_vars() {
    const size_t size_X = M * abs(incX);
    const size_t size_Y = N * abs(incY);
    const size_t size_A = M * lda;

    X = (float*)aligned_alloc(32, size_X * sizeof(float));
    Y = (float*)aligned_alloc(32, size_Y * sizeof(float));
    A = (float*)aligned_alloc(32, size_A * sizeof(float));

    for (size_t k = 0; k < size_X; k++) {
        X[k] = 1.0f + k * 0.001f;
    }
    for (size_t k = 0; k < size_Y; k++) {
        Y[k] = 2.0f + k * 0.002f;
    }
    for (size_t k = 0; k < size_A; k++) {
        A[k] = 0.5f;
    }
}