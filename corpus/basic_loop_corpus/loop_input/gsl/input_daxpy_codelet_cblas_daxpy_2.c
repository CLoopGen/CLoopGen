#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double alpha;
double *X;
int incX;
double *Y;
int incY;
int i;
int ix;
int iy;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime on modern CPU
    // Assuming moderate memory bandwidth usage, aim for ~64-128MB of data
    N = 16777216;  // 16M elements -> ~128MB total (two arrays, each ~64MB)
    
    alpha = 1.5;
    incX = 1;
    incY = 1;
    ix = 0;
    iy = 0;
    
    // Allocate aligned memory for better performance
    X = (double*)aligned_alloc(32, N * sizeof(double));
    Y = (double*)aligned_alloc(32, N * sizeof(double));
    
    // Initialize arrays to avoid undefined behavior
    for (int j = 0; j < N; j++) {
        X[j] = 1.0 + (j % 1000) * 0.001;
        Y[j] = 2.0 + (j % 1000) * 0.002;
    }
}