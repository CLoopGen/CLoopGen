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

MAT *A;
MAT *C;
int i;
int j;

void init_vars() {
    A = (MAT*)malloc(sizeof(MAT));
    C = (MAT*)malloc(sizeof(MAT));

    A->m = 1000;
    A->n = 1000;
    A->max_m = A->m;
    A->max_n = A->n;
    A->max_size = A->m * A->n;

    C->m = A->m;
    C->n = A->n;
    C->max_m = C->m;
    C->max_n = C->n;
    C->max_size = C->m * C->n;

    A->base = (double*)calloc(A->max_size, sizeof(double));
    C->base = (double*)calloc(C->max_size, sizeof(double));

    A->me = (double**)malloc(A->m * sizeof(double*));
    C->me = (double**)malloc(C->m * sizeof(double*));

    for (u_int idx = 0; idx < A->m; idx++) {
        A->me[idx] = A->base + idx * A->n;
        C->me[idx] = C->base + idx * C->n;
    }
}