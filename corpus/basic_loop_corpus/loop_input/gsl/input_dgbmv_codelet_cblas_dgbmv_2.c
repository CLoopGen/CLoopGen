#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

double alpha;
double *A;
int lda;
double *X;
int incX;
double *Y;
int incY;
int i;
int j;
int lenX;
int lenY;
int L;
int U;
int iy;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime on modern CPU
    // Based on typical performance, aim for moderate-sized matrices
    lenX = 2048;
    lenY = 2048;
    L = 50;        // lower bandwidth
    U = 50;        // upper bandwidth
    incX = 1;
    incY = 1;
    alpha = 1.732;

    // Allocate arrays with appropriate sizes
    // A is a band matrix stored in ldaxlenY format, with L+U+1 non-zero diagonals
    lda = L + U + 1;
    A = (double*)aligned_alloc(64, (size_t)lda * (size_t)lenY * sizeof(double));
    X = (double*)aligned_alloc(64, (size_t)lenX * sizeof(double));
    Y = (double*)aligned_alloc(64, (size_t)lenY * sizeof(double));

    // Initialize arrays to avoid NaN and infinities
    for (int k = 0; k < lda * lenY; k++) {
        A[k] = ((double)rand() / RAND_MAX) * 0.01;
    }
    for (int k = 0; k < lenX; k++) {
        X[k] = ((double)rand() / RAND_MAX) * 0.01;
    }
    for (int k = 0; k < lenY; k++) {
        Y[k] = ((double)rand() / RAND_MAX) * 0.01;
    }

    // Initialize loop indices
    i = 0;
    j = 0;
    iy = 0;
}