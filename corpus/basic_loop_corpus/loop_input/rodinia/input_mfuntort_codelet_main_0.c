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

MAT *TMP;
VEC *x;
VEC *b;
double c;
int i;
int j;

void init_vars() {
    x = (VEC *)malloc(sizeof(VEC));
    b = (VEC *)malloc(sizeof(VEC));
    TMP = (MAT *)malloc(sizeof(MAT));

    // Set dimensions to achieve ~0.01s runtime
    // The inner loop runs (b->dim - 1) iterations, outer loop x->dim
    // Total operations roughly x->dim * b->dim
    // On modern CPU, aim for ~10M operations for ~0.01s given this polynomial evaluation
    const u_int size = 3000;
    
    x->dim = size;
    x->max_dim = size;
    x->ve = (double *)malloc(x->max_dim * sizeof(double));
    
    b->dim = size;
    b->max_dim = size;
    b->ve = (double *)malloc(b->max_dim * sizeof(double));
    
    TMP->m = size;
    TMP->n = size;
    TMP->max_m = size;
    TMP->max_n = size;
    TMP->max_size = size * size;
    TMP->me = (double **)malloc(TMP->max_m * sizeof(double *));
    TMP->base = (double *)malloc(TMP->max_m * TMP->max_n * sizeof(double));
    
    // Initialize TMP->me to point into base with proper rows
    for (i = 0; i < (int)TMP->m; i++) {
        TMP->me[i] = &(TMP->base[i * TMP->n]);
    }
    
    // Initialize x and b arrays with non-zero values
    for (i = 0; i < (int)x->dim; i++) {
        x->ve[i] = 1.0 + (double)i * 0.0001;
    }
    for (i = 0; i < (int)b->dim; i++) {
        b->ve[i] = 2.0 + (double)i * 0.0002;
    }
    
    c = 0.0;
}