#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 2048;
double alpha = 1.5;
double *X;
int incX = 1;
double *A;
int lda = 2048;
int i;
int j;
int ix = 0;

void init_vars() {
    X = (double*)aligned_alloc(32, N * incX * sizeof(double));
    A = (double*)aligned_alloc(32, N * lda * sizeof(double));

    for (int k = 0; k < N * incX; k++) {
        X[k] = (double)(k % 123) / 100.0;
    }

    for (int k = 0; k < N * lda; k++) {
        A[k] = (double)(k % 256) / 50.0;
    }
}