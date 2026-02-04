#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N;
double beta;
double *C;
int ldc;
int i;
int j;

void init_vars() {
    // Set matrix size to achieve roughly 1-256MB of data
    // For double precision, each element is 8 bytes
    // We want the total data touched to be in range ~1MB-256MB
    // The loop accesses upper triangular part of N x N matrix
    // Approximate number of elements: N*(N+1)/2
    // Aim for about 16 million elements -> ~128MB
    
    N = 5000;  // This gives about 12.5M elements in upper triangle
    ldc = N;   // Leading dimension matches N
    
    beta = 1.5; // Arbitrary scaling factor
    
    // Allocate column-major matrix of size N*N
    C = (double*)aligned_alloc(32, N * ldc * sizeof(double));
    
    // Initialize matrix with non-zero values to make scaling observable
    for (int idx = 0; idx < N * ldc; idx++) {
        C[idx] = (double)(idx % 100) / 10.0;
    }
}