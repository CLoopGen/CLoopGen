#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1000;
double alpha = 1.5;
double *X;
int incX = 1;
double *Y;
int incY = 1;
double *Ap;
int i;
int j;
int ix = 0;
int iy = 0;

void init_vars() {
    X = (double*)aligned_alloc(32, N * sizeof(double));
    Y = (double*)aligned_alloc(32, N * sizeof(double));
    // Size of Ap: upper triangular part including diagonal of N x N symmetric matrix
    // Number of elements = N*(N+1)/2
    Ap = (double*)aligned_alloc(32, ((size_t)N * (N + 1) / 2) * sizeof(double));

    for (int k = 0; k < N; k++) {
        X[k] = (double)(k % 13) * 0.5;
        Y[k] = (double)(k % 17) * 0.3;
    }

    for (size_t k = 0; k < ((size_t)N * (N + 1) / 2); k++) {
        Ap[k] = 0.0;
    }
}