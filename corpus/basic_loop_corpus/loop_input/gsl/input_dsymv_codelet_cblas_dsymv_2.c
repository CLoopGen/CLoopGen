#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N;
double alpha;
double *A;
int lda;
double *X;
int incX;
double *Y;
int incY;
int i;
int j;
int ix;
int iy;

void init_vars() {
    N = 1024;
    alpha = 1.5;
    lda = N;
    incX = 1;
    incY = 1;
    ix = 0;
    iy = 0;

    A = (double*)aligned_alloc(64, sizeof(double) * N * lda);
    X = (double*)aligned_alloc(64, sizeof(double) * N * abs(incX));
    Y = (double*)aligned_alloc(64, sizeof(double) * N * abs(incY));

    for (int idx = 0; idx < N; idx++) {
        X[idx * incX] = 1.0 / (idx + 1);
        Y[idx * incY] = 2.0;
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            A[lda * row + col] = (row <= col) ? 1.0 : 0.0;
        }
    }
}