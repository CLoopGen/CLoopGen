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
int i;
int j;

void init_vars() {
    A = (MAT*)malloc(sizeof(MAT));
    A->m = 512;
    A->n = 512;
    A->max_m = A->m;
    A->max_n = A->n;
    A->max_size = A->m * A->n;
    A->base = (double*)calloc(A->max_size, sizeof(double));
    A->me = (double**)malloc(A->m * sizeof(double*));
    for (u_int idx = 0; idx < A->m; idx++) {
        A->me[idx] = A->base + idx * A->n;
    }
}