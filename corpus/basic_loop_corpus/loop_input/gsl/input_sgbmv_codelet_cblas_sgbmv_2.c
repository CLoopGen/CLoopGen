#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float alpha;
float *A;
int lda;
float *X;
int incX;
float *Y;
int incY;
int i;
int j;
int lenX;
int lenY;
int L;
int U;
int iy;

void init_vars() {
    lenX = 2048;
    lenY = 2048;
    L = 50;
    U = 50;
    incX = 1;
    incY = 1;
    alpha = 1.5f;
    lda = lenX + 2 * L; // Ensure A has enough columns to cover bandwidth

    X = (float*)aligned_alloc(32, lenX * sizeof(float));
    Y = (float*)aligned_alloc(32, lenY * sizeof(float));
    A = (float*)aligned_alloc(32, lenY * lda * sizeof(float));

    for (int idx = 0; idx < lenX; idx++) {
        X[idx] = (float)(rand() % 100) / 100.0f;
    }

    for (int idx = 0; idx < lenY; idx++) {
        Y[idx] = (float)(rand() % 100) / 100.0f;
    }

    for (int idx = 0; idx < lenY * lda; idx++) {
        A[idx] = (float)(rand() % 100) / 100.0f;
    }

    i = 0;
    j = 0;
    iy = 0;
}