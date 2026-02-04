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

MAT *U;
VEC *x;
VEC *out;
double sum;
int i;
int j;
int limit;

void init_vars() {
    limit = 1000; // Determines problem size for ~0.01 sec runtime

    // Allocate U matrix: limit x limit, row-major with pointer array
    U = (MAT*)calloc(1, sizeof(MAT));
    U->max_m = limit;
    U->max_n = limit;
    U->max_size = limit * limit;
    U->me = (double**)calloc(limit, sizeof(double*));
    U->base = (double*)calloc(limit * limit, sizeof(double));
    for (i = 0; i < limit; i++) {
        U->me[i] = &U->base[i * limit];
    }

    // Allocate x vector
    x = (VEC*)calloc(1, sizeof(VEC));
    x->max_dim = limit;
    x->ve = (double*)calloc(limit, sizeof(double));

    // Allocate out vector
    out = (VEC*)calloc(1, sizeof(VEC));
    out->max_dim = limit;
    out->ve = (double*)calloc(limit, sizeof(double));

    // Initialize data to avoid NaN/undefined behavior
    for (i = 0; i < limit; i++) {
        x->ve[i] = 1.0;
        for (j = 0; j < limit; j++) {
            U->me[i][j] = (i >= j) ? 1.0 : 0.0; // Lower triangular for safe use in loop
        }
    }

    sum = 0.0;
}