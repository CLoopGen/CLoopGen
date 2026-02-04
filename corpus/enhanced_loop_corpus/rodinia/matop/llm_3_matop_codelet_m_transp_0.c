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

extern MAT *in;
extern MAT *out;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access via Linear Indexing
    // Flatten the 2D array access into consecutive memory accesses using pointer arithmetic.
    // This variant treats the matrix as a contiguous block and uses linear indexing to ensure predictable,
    // cache-friendly access patterns. Assumes that 'base' points to flat storage and matrices are stored
    // in row-major order. We manually compute indices to maintain transpose semantics.
    u_int m = in->m;
    u_int n = in->n;
    double *in_base = in->base;
    double *out_base = out->base;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            // Input accessed consecutively per row: in_base[i*n + j]
            // Output written with stride m: each column j starts at offset j*m
            out_base[j * m + i] = in_base[i * n + j];
        }
    }
}
