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

MAT *out;
VEC *a;
int j;

void init_vars() {
    out = (MAT*)malloc(sizeof(MAT));
    a = (VEC*)malloc(sizeof(VEC));

    out->n = 10000; // determines loop iterations, set to ~10k for ~0.01s runtime
    out->m = out->n;
    out->max_m = out->m;
    out->max_n = out->n;
    out->max_size = out->m * out->n;
    out->me = (double**)malloc(out->m * sizeof(double*));
    out->base = (double*)calloc(out->max_size, sizeof(double));

    for (u_int i = 0; i < out->m; i++) {
        out->me[i] = out->base + i * out->n;
    }

    a->dim = 1;
    a->max_dim = 1;
    a->ve = (double*)malloc(a->max_dim * sizeof(double));
    a->ve[0] = 1.5;
}

// Reset j before each loop invocation if needed externally
// j is modified by the loop, so initialization should be done prior to calling loop()