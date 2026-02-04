#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N = 4096;
float *Ap;
float *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    // Allocate arrays with sufficient size based on N
    // Size of Ap: lower triangular matrix stored in packed form, size N*(N+1)/2
    size_t ap_size = (size_t)N * (N + 1) / 2;
    Ap = (float*)aligned_alloc(32, ap_size * sizeof(float));
    X = (float*)aligned_alloc(32, N * sizeof(float));

    // Initialize scalar variables
    incX = 1;        // typical stride
    nonunit = 1;     // use non-unit scaling
    ix = (incX > 0 ? (N - 1) * incX : 0); // initial index for X

    // Initialize all elements to prevent undefined behavior
    for (size_t k = 0; k < ap_size; k++) {
        Ap[k] = 1.0f + 0.001f * (k % 100);
    }
    for (int k = 0; k < N; k++) {
        X[k] = 2.0f + 0.002f * (k % 50);
    }

    // Ensure loop bounds are valid: outer loop uses i from N down to 1
    // Inner loop accesses X[jx] where jx starts at 0 or (N-1)*(-incX) and increments by incX
    // With incX=1 and j from 0 to i-1, jx goes from 0 to i-1, which is safe if i <= N
}