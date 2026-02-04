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

u_int row;
MAT *mat;
VEC *vec;
u_int i;

void init_vars() {
    // Set data size to target ~0.01 seconds runtime
    // Aim for ~64MB of data (double is 8 bytes, so ~8M elements)
    const u_int n = 8000000 / 100; // Adjusted to ~80KB per vector to stay conservative
    const u_int m = 100;
    
    row = 50; // valid row index less than m
    
    // Allocate mat structure
    mat = (MAT*)malloc(sizeof(MAT));
    mat->m = m;
    mat->n = n;
    mat->max_m = m;
    mat->max_n = n;
    mat->max_size = m * n;
    
    // Allocate base matrix memory
    mat->base = (double*)calloc(m * n, sizeof(double));
    
    // Allocate row pointers
    mat->me = (double**)malloc(m * sizeof(double*));
    for (u_int r = 0; r < m; r++) {
        mat->me[r] = &mat->base[r * n];
    }
    
    // Allocate vec structure
    vec = (VEC*)malloc(sizeof(VEC));
    vec->dim = n;
    vec->max_dim = n;
    vec->ve = (double*)malloc(n * sizeof(double));
}