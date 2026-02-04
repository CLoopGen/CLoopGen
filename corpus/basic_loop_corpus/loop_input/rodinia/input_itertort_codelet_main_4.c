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

VEC *x;
VEC *y;
int j;
MAT *Q;
MAT *H;

void init_vars() {
    const u_int size = 10000; // Adjusted to ensure ~0.01 sec runtime

    x = (VEC*)malloc(sizeof(VEC));
    y = (VEC*)malloc(sizeof(VEC));
    Q = (MAT*)malloc(sizeof(MAT));
    H = (MAT*)malloc(sizeof(MAT));

    x->dim = size;
    x->max_dim = size;
    x->ve = (double*)calloc(size, sizeof(double));

    y->dim = size;
    y->max_dim = size;
    y->ve = (double*)calloc(size, sizeof(double));

    Q->m = size;
    Q->n = size;
    Q->max_m = size;
    Q->max_n = size;
    Q->max_size = size * size;
    Q->base = (double*)calloc(size * size, sizeof(double));
    Q->me = (double**)malloc(size * sizeof(double*));
    for (u_int i = 0; i < size; i++) {
        Q->me[i] = Q->base + i * size;
    }

    H->m = size;
    H->n = size;
    H->max_m = size;
    H->max_n = size;
    H->max_size = size * size;
    H->base = (double*)calloc(size * size, sizeof(double));
    H->me = (double**)malloc(size * sizeof(double*));
    for (u_int i = 0; i < size; i++) {
        H->me[i] = H->base + i * size;
    }

    for (u_int i = 0; i < size; i++) {
        x->ve[i] = 1.0 + i * 0.01;
        y->ve[i] = 2.0 + i * 0.02;
    }
}