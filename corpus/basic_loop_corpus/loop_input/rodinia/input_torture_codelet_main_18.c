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

VEC *u;
MAT *A;
MAT *D;
int i;

void init_vars() {
    // Set matrix dimensions to ensure loop runs enough times for measurable duration
    // Aim for ~100 million iterations to achieve ~0.01 sec runtime on modern CPUs
    u_int size = 10000;  // Adjusted to avoid excessive memory use while maintaining performance

    A = (MAT *)malloc(sizeof(MAT));
    D = (MAT *)malloc(sizeof(MAT));
    u = (VEC *)malloc(sizeof(VEC));

    A->m = size;
    A->n = size;
    A->max_m = size;
    A->max_n = size;
    A->max_size = size * size;
    A->me = (double **)malloc(size * sizeof(double *));
    A->base = (double *)calloc(size * size, sizeof(double));
    for (u_int idx = 0; idx < size; idx++) {
        A->me[idx] = &(A->base[idx * size]);
    }

    D->m = size;
    D->n = size;
    D->max_m = size;
    D->max_n = size;
    D->max_size = size * size;
    D->me = (double **)malloc(size * sizeof(double *));
    D->base = (double *)calloc(size * size, sizeof(double));
    for (u_int idx = 0; idx < size; idx++) {
        D->me[idx] = &(D->base[idx * size]);
    }

    u->dim = size;
    u->max_dim = size;
    u->ve = (double *)malloc(size * sizeof(double));
    for (u_int idx = 0; idx < size; idx++) {
        u->ve[idx] = 1.0 + idx * 0.1;
    }
}