#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern MAT *C;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive row-major linearized access using base pointer
    // Assuming the matrix data is stored contiguously in C->base and me[i] points into it
    // We directly modify the diagonal elements via linear indexing using base array
    double *base = C->base;
    u_int size_m = C->m;
    for (i = 0; i < size_m; i++) {
        u_int linear_index = i * size_m + i; // Diagonal element at (i,i) in row-major
        base[linear_index] = base[linear_index] - 1.;
    }
}
