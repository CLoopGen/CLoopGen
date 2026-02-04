#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;

double *A;
int lda;
double *X;
int incX;
int nonunit;
int ix;
int jx;
int i;
int j;

void init_vars() {
    // Allocate A as a column-major matrix of size N x N
    lda = N;
    A = (double*)aligned_alloc(32, sizeof(double) * lda * N);
    
    // Allocate X vector of length N
    X = (double*)aligned_alloc(32, sizeof(double) * N);

    // Initialize scalar parameters
    incX = 1;         // typical stride
    nonunit = 1;      // implies diagonal scaling
    ix = 0;           // initial index for X

    // Initialize arrays to meaningful values to avoid NaN or zero dominance
    for (int idx = 0; idx < N; idx++) {
        X[idx] = 1.0 + idx * 0.001;
    }

    for (int col = 0; col < N; col++) {
        for (int row = 0; row < N; row++) {
            int k = col * lda + row;
            if (row > col) {
                A[k] = (double)(rand() % 100) / 100.0;  // lower triangle: random
            } else if (row == col) {
                A[k] = 1.0 + (rand() % 50) / 100.0;     // unit or scaled diagonal
            } else {
                A[k] = 0.0;                             // upper triangle (not accessed)
            }
        }
    }
}