#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha;
double *A;
int lda;
double *X;
int incX;
double *Y;
int incY;
int i;
int j;
int lenX;
int lenY;
int ix;

void init_vars() {
    lenX = 2048;
    lenY = 2048;
    lda = lenY;
    incX = 1;
    incY = 1;
    alpha = 1.5;

    A = (double*)aligned_alloc(64, sizeof(double) * lda * lenX);
    X = (double*)aligned_alloc(64, sizeof(double) * lenX);
    Y = (double*)aligned_alloc(64, sizeof(double) * lenY);

    for (int k = 0; k < lenX; k++) {
        X[k] = 1.0 + k * 0.001;
    }
    for (int k = 0; k < lenY; k++) {
        Y[k] = 2.0 + k * 0.002;
    }
    for (int k = 0; k < lda * lenX; k++) {
        A[k] = 0.001 * k;
    }

    ix = 0;
}