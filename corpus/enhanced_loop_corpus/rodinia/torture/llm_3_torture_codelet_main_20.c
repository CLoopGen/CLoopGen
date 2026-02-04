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
    // Variant 2: Consecutive memory access via flattened base array
    // Assuming D->base is a contiguous block storing matrix data in row-major order,
    // and diagonal elements are accessed indirectly through index calculation.
    // This changes the access pattern to use a linear array with computed indices.
    double *base = D->base;
    u_int n = D->max_n; // assumed leading dimension or row stride
    for (i = 0; i < D->m; i++) {
        u_int idx = i * n + i; // diagonal element at [i][i] in flattened storage
        base[idx] = base[idx] - 1.;
    }
}
