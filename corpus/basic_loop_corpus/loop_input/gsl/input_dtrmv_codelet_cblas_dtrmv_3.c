#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;

double *A;
int lda;
double *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    lda = N;
    incX = 1;
    nonunit = 1;
    i = 0;
    j = 0;
    ix = 0;

    A = (double*)aligned_alloc(64, sizeof(double) * N * lda);
    X = (double*)aligned_alloc(64, sizeof(double) * (N + (N - 1) * abs(incX)));

    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = (double)(idx % 127) / 127.0;
    }
    for (int idx = 0; idx < N; idx++) {
        int offset = idx * abs(incX);
        X[offset] = (double)(idx % 255) / 255.0;
    }
}