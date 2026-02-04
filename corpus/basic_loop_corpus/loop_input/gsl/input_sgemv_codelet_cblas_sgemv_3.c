#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

float alpha = 1.5f;

int lenX = 2000;
int lenY = 2000;
int lda = 2000;
int incX = 1;
int incY = 1;
int i = 0;
int j = 0;
int ix = 0;

float *A;
float *X;
float *Y;

void init_vars() {
    const size_t size_A = (size_t)lda * (size_t)lenY * sizeof(float);
    const size_t size_X = (size_t)lenX * sizeof(float);
    const size_t size_Y = (size_t)lenY * sizeof(float);

    A = (float*)aligned_alloc(32, size_A);
    X = (float*)aligned_alloc(32, size_X);
    Y = (float*)aligned_alloc(32, size_Y);

    for (size_t k = 0; k < size_A / sizeof(float); k++) {
        A[k] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }
    for (int k = 0; k < lenX; k++) {
        X[k] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }
    for (int k = 0; k < lenY; k++) {
        Y[k] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }

    ix = 0;
}