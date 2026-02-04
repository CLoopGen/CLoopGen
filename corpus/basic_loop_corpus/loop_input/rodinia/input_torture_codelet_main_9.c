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

VEC *w;
MAT *D;
int i;

void init_vars() {
    w = (VEC *)malloc(sizeof(VEC));
    D = (MAT *)malloc(sizeof(MAT));

    w->dim = 10000;
    w->max_dim = w->dim;
    w->ve = (double *)malloc(w->dim * sizeof(double));

    D->m = w->dim;
    D->n = w->dim;
    D->max_m = D->m;
    D->max_n = D->n;
    D->max_size = D->m * D->n;
    D->me = (double **)malloc(D->m * sizeof(double *));
    D->base = (double *)malloc(D->m * D->n * sizeof(double));

    for (u_int idx = 0; idx < D->m; idx++) {
        D->me[idx] = &(D->base[idx * D->n]);
    }

    for (u_int idx = 0; idx < w->dim; idx++) {
        w->ve[idx] = (idx % 2) ? 0.6 : 0.4;
    }
}