#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
double alpha = 1.5;
double *X;
int incX = 1;
double *Y;
int incY = 1;
double *A;
int lda = 1024;
int i;
int j;
int ix = 0;
int iy = 0;

void init_vars() {
    X = (double *)aligned_alloc(32, N * incX * sizeof(double));
    Y = (double *)aligned_alloc(32, N * incY * sizeof(double));
    A = (double *)aligned_alloc(32, N * lda * sizeof(double));

    for (int k = 0; k < N * incX; k++) {
        X[k] = 1.0 + k * 0.1;
    }
    for (int k = 0; k < N * incY; k++) {
        Y[k] = 2.0 + k * 0.2;
    }
    for (int k = 0; k < N * lda; k++) {
        A[k] = 0.5;
    }
}