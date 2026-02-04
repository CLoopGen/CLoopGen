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

extern MAT *D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access via flattened indexing
    // Access the matrix as if it were stored in a contiguous block using row-major layout.
    // Assumes that D->base holds the entire matrix data contiguously, and D->me[i] points into this block.
    // We traverse diagonal elements but compute their position in linear memory.
    double *base = D->base;
    int n = D->n;
    for (i = 0; i < D->m; i++) {
        // Diagonal element at (i,i) corresponds to base[i * n + i]
        base[i * n + i] = base[i * n + i] - 1.;
    }
}
