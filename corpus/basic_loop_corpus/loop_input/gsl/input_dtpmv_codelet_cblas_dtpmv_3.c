#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 2048;
double *Ap = NULL;
double *X = NULL;
int incX = 1;
int i = 0;
int j = 0;
int nonunit = 1;
int ix = 0;

void init_vars() {
    // Allocate Ap as a packed lower triangular matrix: size N*(N+1)/2
    Ap = (double*)aligned_alloc(64, sizeof(double) * ((size_t)N * (N + 1)) / 2);
    
    // Allocate X with enough elements for indexing via ix and jx with incX steps
    X = (double*)aligned_alloc(64, sizeof(double) * (N * abs(incX) + 1));

    // Initialize Ap with dummy data (e.g., 1.0 on diagonal, 0.5 elsewhere)
    for (int row = 0; row < N; row++) {
        for (int col = 0; col <= row; col++) {
            size_t idx = (row * (row + 1)) / 2 + col;
            Ap[idx] = (row == col) ? 1.0 : 0.5;
        }
    }

    // Initialize X with sequential values
    for (int k = 0; k < N; k++) {
        int offset = (incX > 0 ? 0 : (N - 1) * (-incX)) + k * incX;
        X[offset] = (double)(k + 1);
    }

    // Reset loop indices
    i = 0;
    j = 0;
    ix = (incX > 0 ? 0 : (N - 1) * (-incX));
    nonunit = 1;
}