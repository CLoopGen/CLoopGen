#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2000;
int K = 50;
double *A;
int lda = 100;
double *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix = 0;

void init_vars() {
    A = (double*)aligned_alloc(64, sizeof(double) * lda * N);
    X = (double*)aligned_alloc(64, sizeof(double) * (N * abs(incX) + 1));

    for (int idx = 0; idx < lda * N; idx++) {
        A[idx] = (double)(idx % 100) / 10.0;
    }

    for (int idx = 0; idx < N * abs(incX) + 1; idx++) {
        X[idx] = (double)(idx % 50) / 5.0;
    }
}