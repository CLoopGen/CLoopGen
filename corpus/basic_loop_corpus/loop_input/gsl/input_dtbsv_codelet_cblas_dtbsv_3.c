#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2000;
int K = 50;
double *A;
int lda;
double *X;
int incX;
int nonunit;
int i;
int j;
int ix;

void init_vars() {
    // Set matrix and vector parameters
    N = 2000;        // Size of the system
    K = 50;          // Bandwidth (number of superdiagonals)
    lda = K + 1;     // Leading dimension for band storage: diagonals stored in rows
    incX = 1;        // Increment for X
    nonunit = 1;     // Assume non-unit diagonal

    // Allocate A as a band matrix with (K+1) diagonals, size (K+1) x N
    A = (double*)calloc((size_t)(lda) * N, sizeof(double));
    if (!A) exit(1);

    // Allocate X vector of size N
    X = (double*)malloc((size_t)N * sizeof(double));
    if (!X) exit(1);

    // Initialize X with sample values
    for (int idx = 0; idx < N; ++idx) {
        X[idx] = 1.0 + idx * 0.1;
    }

    // Initialize band matrix A: fill with small random-like values
    for (int j = 0; j < N; ++j) {
        int k_start = (j < K ? K - j : 0); // Adjust for left edge
        int k_end = K;
        for (int k = k_start; k <= k_end; ++k) {
            int row = k;
            int col = j;
            double val = 0.01 + (k + j) * 0.001;
            if (row == K && col == j) val += 2.0; // Diagonal dominance
            A[row + lda * col] = val;
        }
    }

    // Initialize loop index variables
    i = N - 1;       // Start from last row
    ix = (incX > 0 ? 0 : (N - 1) * (-incX)); // Initial offset in X
    ix += (N - 1) * incX; // Point to last element accessed
}