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

MAT *T;
int j;
int limit;
VEC *tmp1_re;

void init_vars() {
    T = (MAT *)malloc(sizeof(MAT));
    tmp1_re = (VEC *)malloc(sizeof(VEC));

    limit = 1000;
    T->m = 2000;
    tmp1_re->dim = 2000;

    T->max_m = T->m;
    T->max_n = 1;
    T->max_size = T->m;
    T->n = 1;
    T->me = NULL;
    T->base = NULL;

    tmp1_re->max_dim = tmp1_re->dim;
    tmp1_re->ve = (double *)calloc(tmp1_re->dim, sizeof(double));
}