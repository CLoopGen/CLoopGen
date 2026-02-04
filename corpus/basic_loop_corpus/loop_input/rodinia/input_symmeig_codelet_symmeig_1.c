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

MAT *A;
VEC *out;
int i;
MAT *tmp;
VEC *b;

void init_vars() {
    const u_int size = 10000; // Adjusted for ~0.01 sec runtime

    A = (MAT *)malloc(sizeof(MAT));
    tmp = (MAT *)malloc(sizeof(MAT));
    out = (VEC *)malloc(sizeof(VEC));
    b = (VEC *)malloc(sizeof(VEC));

    A->m = size;
    A->n = size;
    A->max_m = size;
    A->max_n = size;
    A->max_size = size * size;
    A->me = NULL;
    A->base = NULL;

    tmp->m = size;
    tmp->n = size;
    tmp->max_m = size;
    tmp->max_n = size;
    tmp->max_size = size * size;
    tmp->base = (double *)calloc(size * size, sizeof(double));
    tmp->me = (double **)malloc(size * sizeof(double *));
    for (u_int i = 0; i < size; i++) {
        tmp->me[i] = tmp->base + i * size;
    }

    out->dim = size;
    out->max_dim = size;
    out->ve = (double *)calloc(size, sizeof(double));

    b->dim = size;
    b->max_dim = size;
    b->ve = (double *)calloc(size, sizeof(double));

    for (u_int i = 0; i < size; i++) {
        for (u_int j = 0; j < size; j++) {
            tmp->me[i][j] = (double)(i + j);
        }
    }
}