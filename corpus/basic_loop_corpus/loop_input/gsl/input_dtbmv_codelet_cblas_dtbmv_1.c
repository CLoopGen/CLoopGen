#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
int K = 512;
double *A;
int lda;
double *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    lda = K + 1;
    incX = 1;
    nonunit = 1;

    A = (double*)aligned_alloc(64, sizeof(double) * lda * N);
    X = (double*)aligned_alloc(64, sizeof(double) * N);

    for (int idx = 0; idx < N; idx++) {
        X[idx] = 1.0 + idx * 0.001;
    }

    for (int i_idx = 0; i_idx < N; i_idx++) {
        for (int k_idx = 0; k_idx <= K && (K - i_idx + k_idx) >= 0 && k_idx < lda; k_idx++) {
            A[lda * i_idx + k_idx] = 0.1 + i_idx * 0.0001 + k_idx * 0.0002;
        }
    }

    ix = (incX > 0 ? 0 : (N - 1) * (-incX)) + (N - 1) * incX;
}