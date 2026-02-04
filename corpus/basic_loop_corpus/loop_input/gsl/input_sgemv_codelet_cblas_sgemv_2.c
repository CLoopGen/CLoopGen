#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha = 1.5f;

int lenX = 2048;
int lenY = 2048;
int lda = 2048;
int incX = 1;
int incY = 1;
int i = 0;
int j = 0;
int iy = 0;

float *A = NULL;
float *X = NULL;
float *Y = NULL;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * (size_t)lda * (size_t)lenY);
    X = (float*)aligned_alloc(32, sizeof(float) * (size_t)lenX);
    Y = (float*)aligned_alloc(32, sizeof(float) * (size_t)lenY);

    for (int idx = 0; idx < lenY * lda; idx++) {
        A[idx] = (float)(idx % 100) / 100.0f;
    }
    for (int idx = 0; idx < lenX; idx++) {
        X[idx] = (float)(idx % 50) / 50.0f;
    }
    for (int idx = 0; idx < lenY; idx++) {
        Y[idx] = (float)(idx % 75) / 75.0f;
    }

    alpha = 1.5f;
    iy = 0;
}