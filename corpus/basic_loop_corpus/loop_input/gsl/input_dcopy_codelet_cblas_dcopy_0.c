#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int N;
double *X;
int incX;
double *Y;
int incY;
int i;
int ix;
int iy;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume modern CPU can handle tens of millions of iterations per second
    // Aim for 10-50 million elements to hit ~0.01 sec range
    
    N = 20000000;  // 20 million elements - reasonable for ~0.01 sec
    
    // Allocate arrays with proper alignment for double
    X = (double*)aligned_alloc(32, N * sizeof(double));
    Y = (double*)aligned_alloc(32, N * sizeof(double));
    
    if (X == NULL || Y == NULL) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize array contents
    for (int j = 0; j < N; j++) {
        X[j] = 1.0 + (double)j * 0.001;
        Y[j] = 0.0;
    }
    
    // Set stride values - use unit stride for simplicity and performance
    incX = 1;
    incY = 1;
    
    // Initialize starting indices
    ix = 0;
    iy = 0;
}