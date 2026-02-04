#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N;
double beta;
void *C;
int ldc;
int i;
int j;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // The loop runs about (N*(N+1))/2 iterations, so we choose N such that
    // memory touched is in the 1MB-256MB range.
    // Each iteration accesses 2 doubles (16 bytes), and total written elements ~ N^2
    // So total memory written ~ 16 * N^2 bytes.
    // For 64MB target: N^2 ~ 4M => N ~ 2000
    N = 2048;
    
    beta = 1.5;
    
    ldc = N; // square matrix layout
    
    // Allocate C as array of double complex or double[2] layout: ldc x N, each element has 2 doubles
    // Total size: ldc * N * 2 * sizeof(double)
    size_t alloc_size = ldc * N * 2 * sizeof(double);
    C = aligned_alloc(32, alloc_size);
    
    // Initialize C to non-zero values to make scaling visible
    double *C_ptr = (double *)C;
    for (int idx = 0; idx < ldc * N * 2; idx++) {
        C_ptr[idx] = (double)(idx % 123 + 1) / (idx % 47 + 1);
    }
}

// Provide definitions for extern variables
int N = 0;
double beta = 0.0;
void *C = NULL;
int ldc = 0;
int i = 0;
int j = 0;