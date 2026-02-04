#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
double *Ap;
double *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix;

void init_vars() {
    // Allocate Ap as a packed lower triangular matrix in column-major format
    // Size: N*(N+1)/2 elements
    Ap = (double*)calloc(N * (N + 1) / 2, sizeof(double));
    if (!Ap) exit(1);

    // Allocate X vector
    X = (double*)malloc(N * sizeof(double));
    if (!X) exit(1);

    // Initialize X with sample values
    for (int k = 0; k < N; k++) {
        X[k] = 1.0 + k * 0.1;
    }

    // Initialize Ap: diagonal elements non-zero, ensure no division by zero
    int idx = 0;
    for (int col = 0; col < N; col++) {
        for (int row = col; row < N; row++) {
            Ap[idx++] = 1.0 + (col * N + row) * 0.01;
        }
    }

    // Initialize loop indices
    i = N - 1;
    ix = (N - 1) * incX;
}