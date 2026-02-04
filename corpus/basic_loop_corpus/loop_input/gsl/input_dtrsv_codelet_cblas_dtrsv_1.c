#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
double *A;
int lda = 4096;
double *X;
int incX = 1;
int nonunit = 1;
int ix = 0;
int jx = 0;
int i = 0;
int j = 0;

void init_vars() {
    A = (double*)aligned_alloc(32, sizeof(double) * N * lda);
    X = (double*)aligned_alloc(32, sizeof(double) * N * abs(incX));

    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = (double)(rand()) / RAND_MAX * 2.0 - 1.0;
    }
    for (int idx = 0; idx < N; idx++) {
        X[idx * incX] = (double)(rand()) / RAND_MAX * 2.0 - 1.0;
    }

    for (int i_diag = 0; i_diag < N; i_diag++) {
        A[lda * i_diag + i_diag] = 1.0 + (double)(rand()) / RAND_MAX;
    }
}