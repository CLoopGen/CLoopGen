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

u_int col;
MAT *mat;
VEC *vec;
u_int i;

void init_vars() {
    // Set matrix dimensions to achieve ~100ms runtime
    // Each iteration does one load and one store -> very fast
    // To reach ~0.01s, we need enough data to take that long
    // Assume modern CPU can do ~1e9 ops/sec -> need ~1e7 iterations for 0.01s
    u_int size = 128 * 1024 * 1024 / sizeof(double); // ~128MB of data
    if (size < 10000) size = 10000; // Ensure minimum size
    
    mat = (MAT*)calloc(1, sizeof(MAT));
    vec = (VEC*)calloc(1, sizeof(VEC));
    
    mat->m = size;
    mat->n = 10; // arbitrary width
    mat->max_m = mat->m;
    mat->max_n = mat->n;
    mat->max_size = mat->m * mat->n;
    
    mat->base = (double*)calloc(mat->m * mat->n, sizeof(double));
    mat->me = (double**)calloc(mat->m, sizeof(double*));
    for (u_int idx = 0; idx < mat->m; idx++) {
        mat->me[idx] = mat->base + idx * mat->n;
        // Initialize with some values
        for (u_int j = 0; j < mat->n; j++) {
            mat->me[idx][j] = (double)(idx * mat->n + j);
        }
    }
    
    vec->dim = mat->m;
    vec->max_dim = vec->dim;
    vec->ve = (double*)calloc(vec->dim, sizeof(double));
    
    col = 5; // choose a valid column within [0, n-1]
}