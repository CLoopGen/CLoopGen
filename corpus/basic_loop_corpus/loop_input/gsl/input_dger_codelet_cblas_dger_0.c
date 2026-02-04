#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int M = 1024;
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

void init_vars() {
    X = (double*)malloc(M * sizeof(double));
    Y = (double*)malloc(N * sizeof(double));
    A = (double*)malloc(M * N * sizeof(double));

    for (int k = 0; k < M; k++) {
        X[k] = (double)(k % 127) / 10.0;
    }

    for (int k = 0; k < N; k++) {
        Y[k] = (double)(k % 131) / 10.0;
    }

    for (int k = 0; k < M * N; k++) {
        A[k] = (double)(k % 137) / 10.0;
    }
}