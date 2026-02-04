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
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

MAT *A;
PERM *block;
VEC *tmp;
int i;
int j;
int n;
double sum;

static double **create_double_matrix(u_int rows, u_int cols) {
    double **m = malloc(rows * sizeof(double*));
    double *data = calloc(rows * cols, sizeof(double));
    for (u_int i = 0; i < rows; i++) {
        m[i] = &data[i * cols];
    }
    return m;
}

static u_int *create_uint_array(u_int size) {
    return calloc(size, sizeof(u_int));
}

static double *create_double_array(u_int size) {
    return calloc(size, sizeof(double));
}

void init_vars() {
    n = 2048;

    A = malloc(sizeof(MAT));
    A->m = n;
    A->n = n;
    A->max_m = n;
    A->max_n = n;
    A->max_size = n * n;
    A->me = create_double_matrix(n, n);
    A->base = calloc(n * n, sizeof(double));

    block = malloc(sizeof(PERM));
    block->size = n;
    block->max_size = n;
    block->pe = create_uint_array(n);
    for (u_int idx = 0; idx < n; idx++) {
        block->pe[idx] = (rand() % 2) ? idx : (idx > 0 ? idx - 1 : 0);
    }

    tmp = malloc(sizeof(VEC));
    tmp->dim = n;
    tmp->max_dim = n;
    tmp->ve = create_double_array(n);
    for (u_int idx = 0; idx < n; idx++) {
        tmp->ve[idx] = 1.0;
    }

    i = 0;
    j = 0;
    sum = 0.0;
}