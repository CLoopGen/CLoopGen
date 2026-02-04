#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef double R;
typedef ptrdiff_t INT;

R *I;
INT n;
INT s0;
INT s1;
INT i0;
INT i1;

void init_vars() {
    // Estimate problem size to achieve around 0.01 seconds runtime
    // The loop runs roughly (n-1)*n/2 iterations, each doing 4 memory accesses
    // Aim for ~10-20 million operations depending on CPU speed
    
    n = 2048;  // This gives about 2M inner iterations, sufficient for 0.01s with some margin
    
    // Set strides to access a 2D matrix in row-major order
    // We're treating I as an n x n matrix
    s0 = n;
    s1 = 1;
    
    // Allocate and initialize array I with size n*n
    I = (R*)aligned_alloc(sizeof(R), sizeof(R) * n * n);
    
    // Initialize array with non-zero values to make swaps observable
    for (INT i = 0; i < n * n; ++i) {
        I[i] = (R)(i + 1);
    }
    
    // Initialize loop indices to safe values (will be overwritten by loop)
    i0 = 0;
    i1 = 0;
}