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

void init_vars() {
    n = 1000; // Size chosen to make loop run ~0.01s

    // Allocate A
    A = (MAT*)malloc(sizeof(MAT));
    A->m = n;
    A->n = n;
    A->max_m = n;
    A->max_n = n;
    A->max_size = n * n;
    A->base = (double*)calloc(n * n, sizeof(double));
    A->me = (double**)malloc(n * sizeof(double*));
    for (int idx = 0; idx < n; idx++) {
        A->me[idx] = A->base + idx * n;
    }

    // Allocate block
    block = (PERM*)malloc(sizeof(PERM));
    block->size = n;
    block->max_size = n;
    block->pe = (u_int*)malloc(n * sizeof(u_int));
    for (int idx = 0; idx < n; idx++) {
        block->pe[idx] = (idx % 2 == 0) ? idx + 1 : idx - 1; // Alternating pattern
    }

    // Allocate tmp
    tmp = (VEC*)malloc(sizeof(VEC));
    tmp->dim = n;
    tmp->max_dim = n;
    tmp->ve = (double*)malloc(n * sizeof(double));
    for (int idx = 0; idx < n; idx++) {
        tmp->ve[idx] = 1.0 / (idx + 1);
    }

    // Initialize scalars
    i = 0;
    j = 0;
    sum = 0.0;
}