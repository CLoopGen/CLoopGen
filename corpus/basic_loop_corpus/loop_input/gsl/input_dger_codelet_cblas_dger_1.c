#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int M = 2048;
int N = 2048;
double alpha = 1.5;
double *X;
int incX = 1;
double *Y;
int incY = 1;
double *A;
int lda = 2048;
int i;
int j;
int jy = 0;

void init_vars() {
    X = (double*)aligned_alloc(64, M * sizeof(double));
    Y = (double*)aligned_alloc(64, N * sizeof(double));
    A = (double*)aligned_alloc(64, M * N * sizeof(double));

    for (int idx = 0; idx < M; idx++) {
        X[idx] = 1.0 + idx * 0.001;
    }
    for (int idx = 0; idx < N; idx++) {
        Y[idx] = 2.0 + idx * 0.002;
    }
    for (int idx = 0; idx < M * N; idx++) {
        A[idx] = 0.0;
    }
}