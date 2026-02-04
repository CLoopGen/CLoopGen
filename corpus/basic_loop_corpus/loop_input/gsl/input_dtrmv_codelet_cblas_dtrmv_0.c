#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double *A;
int lda;
double *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    N = 2048;
    lda = N;
    incX = 1;
    nonunit = 1;

    A = (double*)aligned_alloc(32, sizeof(double) * N * N);
    X = (double*)aligned_alloc(32, sizeof(double) * N);

    for (int idx = 0; idx < N * N; idx++) {
        A[idx] = (double)(idx % 1000) / 1000.0;
    }
    for (int idx = 0; idx < N; idx++) {
        X[idx] = (double)(idx % 500) / 500.0;
    }

    i = 0;
    j = 0;
    ix = 0;
}