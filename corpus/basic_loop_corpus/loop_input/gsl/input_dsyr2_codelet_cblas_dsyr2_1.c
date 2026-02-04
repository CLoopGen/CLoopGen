#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
double alpha = 1.5;

double *X;
int incX = 1;
double *Y;
int incY = 1;
double *A;
int lda;

int i;
int j;
int ix;
int iy;

void init_vars() {
    X = (double*)aligned_alloc(32, N * sizeof(double));
    Y = (double*)aligned_alloc(32, N * sizeof(double));
    A = (double*)aligned_alloc(32, N * N * sizeof(double));
    lda = N;
    ix = 0;
    iy = 0;

    for (int k = 0; k < N; k++) {
        X[k] = (double)(k % 127) / 127.0;
        Y[k] = (double)((k + 50) % 127) / 127.0;
    }

    for (int k = 0; k < N * N; k++) {
        A[k] = 0.0;
    }
}