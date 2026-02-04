#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;

double *A;
int lda = 2048;
double *X;
int incX = 1;
int nonunit = 1;
int ix;
int jx;
int i;
int j;

void init_vars() {
    A = (double*)aligned_alloc(64, sizeof(double) * lda * N);
    X = (double*)aligned_alloc(64, sizeof(double) * N * abs(incX));

    for (int idx = 0; idx < lda * N; ++idx) {
        A[idx] = 1.0 + (idx % 7) * 0.1;
    }

    for (int idx = 0; idx < N; ++idx) {
        X[idx * incX] = 2.0 + (idx % 5) * 0.2;
    }

    ix = (N - 1) * incX;
}