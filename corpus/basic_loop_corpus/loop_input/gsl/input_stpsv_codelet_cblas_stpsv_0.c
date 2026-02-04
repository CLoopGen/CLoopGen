#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

int N;
float *Ap;
float *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    N = 1024; // Choose size so that total data is ~several MB, ensuring loop runtime ~0.01s

    // Allocate Ap: stores upper triangular matrix in packed format (column-major, upper triangle including diagonal)
    // Number of elements in packed upper triangular storage: N*(N+1)/2
    int ap_size = N * (N + 1) / 2;
    Ap = (float*)aligned_alloc(32, ap_size * sizeof(float));
    for (int idx = 0; idx < ap_size; idx++) {
        Ap[idx] = 1.0f + 0.01f * (rand() / (float)RAND_MAX); // Avoid zeros on diagonal
    }

    // Allocate X vector
    int x_size = 1 + (N - 1) * abs(incX) + 1; // Allow margin for strided access
    incX = 1; // Use unit stride for simplicity and performance
    X = (float*)aligned_alloc(32, x_size * sizeof(float));
    for (int idx = 0; idx < x_size; idx++) {
        X[idx] = rand() / (float)RAND_MAX;
    }

    // Initialize loop indices
    i = 0;
    j = 0;
    nonunit = 1; // Enable division by diagonal element
    ix = (N - 1) * incX; // Start from last accessed element

    // Ensure initial values used in loop are consistent
}