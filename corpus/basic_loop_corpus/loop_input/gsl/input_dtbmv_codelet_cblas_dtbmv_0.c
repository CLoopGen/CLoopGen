#include <stdlib.h>
#include <stddef.h>

int N = 2048;
int K = 128;
double *A;
int lda = 256;
double *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix = 0;

void init_vars() {
    A = (double*)aligned_alloc(32, sizeof(double) * lda * N);
    X = (double*)aligned_alloc(32, sizeof(double) * ((N - 1) * abs(incX) + 1));

    for (int idx = 0; idx < lda * N; idx++) {
        A[idx] = (double)(idx % 123) * 0.01;
    }

    for (int idx = 0; idx < N; idx++) {
        int offset = idx * incX;
        X[offset] = (double)(idx % 79) * 0.02;
    }
}