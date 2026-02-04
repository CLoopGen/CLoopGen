#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

VEC *d;
VEC *f;
int i;
int limit;
MAT *A_tmp;

void init_vars() {
    limit = 10000;

    d = (VEC*)malloc(sizeof(VEC));
    f = (VEC*)malloc(sizeof(VEC));
    A_tmp = (MAT*)malloc(sizeof(MAT));

    d->dim = limit;
    d->max_dim = limit;
    d->ve = (double*)malloc(limit * sizeof(double));

    f->dim = limit;
    f->max_dim = limit;
    f->ve = (double*)malloc(limit * sizeof(double));

    A_tmp->m = limit;
    A_tmp->n = limit;
    A_tmp->max_m = limit;
    A_tmp->max_n = limit;
    A_tmp->max_size = limit * limit;
    A_tmp->base = (double*)malloc(limit * limit * sizeof(double));
    A_tmp->me = (double**)malloc(limit * sizeof(double*));
    
    for (int row = 0; row < limit; row++) {
        A_tmp->me[row] = A_tmp->base + row * limit;
        for (int col = 0; col < limit; col++) {
            A_tmp->me[row][col] = (double)(row * limit + col) * 0.5;
        }
    }

    for (int idx = 0; idx < limit; idx++) {
        d->ve[idx] = 0.0;
        f->ve[idx] = 0.0;
    }
}