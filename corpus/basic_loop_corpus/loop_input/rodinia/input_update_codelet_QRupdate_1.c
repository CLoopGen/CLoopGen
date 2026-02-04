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

MAT *R;
VEC *v;
int j;
double temp;

void init_vars() {
    // Set data size to target ~0.01 seconds runtime
    // For simple arithmetic, ~10-20 million iterations typical for 0.01s on modern CPU
    u_int n_size = 16000000;  // 16M elements

    // Allocate R and v
    R = (MAT*)malloc(sizeof(MAT));
    v = (VEC*)malloc(sizeof(VEC));

    // Initialize dimensions
    R->m = 1;
    R->n = n_size;
    R->max_m = 1;
    R->max_n = n_size;
    R->max_size = n_size;

    v->dim = n_size;
    v->max_dim = n_size;

    // Allocate base matrix memory
    R->base = (double*)calloc(n_size, sizeof(double));
    R->me = (double**)malloc(sizeof(double*));
    R->me[0] = R->base;

    // Allocate vector
    v->ve = (double*)malloc(n_size * sizeof(double));

    // Initialize vector elements to avoid NaN/inf issues
    for (u_int i = 0; i < n_size; i++) {
        v->ve[i] = 1.0;
    }

    // Initialize temp
    temp = 2.5;
}