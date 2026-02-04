#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
int K = 128;
double *A;
int lda;
double *X;
int incX;
int nonunit;
int i;
int j;
int ix;

void init_vars() {
    // Initialize parameters to ensure reasonable runtime (~0.01 sec) and memory usage
    N = 4096;
    K = 128;
    lda = 2 * K + 1; // Ensure A has enough columns to cover index: K + j - i, where j <= i
    incX = 1;
    nonunit = 1;
    i = 0;
    j = 0;
    ix = 0;

    // Allocate arrays with appropriate sizes
    // A is an N x (2*K+1) matrix in leading dimension lda storage
    // We use packed band storage: diagonal of A is at position [K], subdiagonals below, superdiagonals above
    A = (double*)aligned_alloc(32, sizeof(double) * lda * N);
    X = (double*)aligned_alloc(32, sizeof(double) * ((N - 1) * abs(incX) + 1));

    // Initialize A and X with meaningful values to avoid NaN/inf and test logic
    for (int row = 0; row < N; row++) {
        for (int k = 0; k < lda; k++) {
            const int diag_offset = k - K; // relative to diagonal
            if (diag_offset >= -(K) && diag_offset <= K && row - diag_offset >= 0 && row - diag_offset < N) {
                // Only valid band entries
                A[lda * row + k] = (diag_offset == 0) ? (2.0 + 0.1 * drand48()) : (0.1 * drand48());
            } else {
                A[lda * row + k] = 0.0;
            }
        }
    }

    for (int idx = 0; idx < N; idx++) {
        X[idx * incX] = 1.0 + 0.1 * drand48();
    }

    // Set initial ix based on incX
    ix = (incX > 0) ? 0 : (N - 1) * (-incX);
}