#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

float alpha;
float *A;
int lda;
float *X;
int incX;
float *Y;
int incY;
int i;
int j;
int lenX;
int lenY;
int L;
int U;
int jx;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime on modern CPU
    // Based on typical performance, choose lenX and lenY around 4000-8000 for reasonable FLOPs
    lenX = 6000;
    lenY = 7000;
    
    // Set band matrix parameters: L = lower bandwidth, U = upper bandwidth
    L = 50;
    U = 50;
    
    // Set scalar factors
    alpha = 1.2f;
    incX = 1;
    incY = 1;
    jx = 0;
    
    // Allocate arrays with appropriate sizes
    // A is a band matrix stored in column-major format with lda rows
    lda = L + U + 1;  // leading dimension of A (diagonals + sub/super diagonals)
    A = (float*)aligned_alloc(32, sizeof(float) * lda * lenX);
    
    X = (float*)aligned_alloc(32, sizeof(float) * (lenX * abs(incX) + 1));
    Y = (float*)aligned_alloc(32, sizeof(float) * (lenY * abs(incY) + 1));
    
    // Initialize arrays to non-zero values to ensure temp != 0 path is taken
    for (int k = 0; k < lda * lenX; k++) {
        A[k] = (float)(drand48() * 2.0 - 1.0);
    }
    
    for (int k = 0; k < lenX * abs(incX) + 1; k++) {
        X[k] = (float)(drand48() * 2.0 - 1.0);
    }
    
    for (int k = 0; k < lenY * abs(incY) + 1; k++) {
        Y[k] = (float)(drand48() * 2.0 - 1.0);
    }
}