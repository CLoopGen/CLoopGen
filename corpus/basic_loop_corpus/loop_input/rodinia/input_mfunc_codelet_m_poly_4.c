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

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

MAT *out;
VEC *a;
int j;

void init_vars() {
    // Allocate and initialize vector a
    a = (VEC*)malloc(sizeof(VEC));
    a->dim = 1;
    a->max_dim = 1;
    a->ve = (double*)calloc(1, sizeof(double));
    a->ve[0] = 1.0;  // Initialize to non-zero value

    // Determine matrix size to achieve desired runtime (~0.01 seconds)
    // For diagonal assignment loop: j from 0 to out->n-1, so we need ~10^6 to 10^7 iterations
    u_int mat_size = 8192;  // Approximately 8K x 8K matrix -> ~8K iterations in loop

    out = (MAT*)malloc(sizeof(MAT));
    out->m = mat_size;
    out->n = mat_size;
    out->max_m = mat_size;
    out->max_n = mat_size;
    out->max_size = mat_size * mat_size;
    out->base = (double*)calloc(mat_size * mat_size, sizeof(double));
    
    // Allocate array of row pointers
    out->me = (double**)malloc(mat_size * sizeof(double*));
    for (u_int i = 0; i < mat_size; i++) {
        out->me[i] = out->base + i * mat_size;
    }
}

// External variables must be defined at file scope