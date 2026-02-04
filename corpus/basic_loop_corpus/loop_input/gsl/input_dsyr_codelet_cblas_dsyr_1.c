#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double alpha;
double *X;
int incX;
double *A;
int lda;
int i;
int j;
int ix;

void init_vars() {
    N = 2048;
    alpha = 1.5;
    incX = 1;
    lda = N;

    X = (double*)aligned_alloc(32, N * sizeof(double));
    A = (double*)aligned_alloc(32, N * N * sizeof(double));

    for (int k = 0; k < N; k++) {
        X[k] = (double)(k + 1);
    }

    for (int k = 0; k < N * N; k++) {
        A[k] = (double)(k % 100) / 100.0;
    }

    i = 0;
    j = 0;
    ix = 0;
}