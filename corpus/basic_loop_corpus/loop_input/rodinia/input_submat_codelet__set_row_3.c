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

MAT *mat;
VEC *vec;
u_int row;
u_int _usr_j0;
u_int j;
u_int lim;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // ~128 MB of double data (each double is 8 bytes)

    mat = (MAT*)calloc(1, sizeof(MAT));
    vec = (VEC*)calloc(1, sizeof(VEC));

    mat->max_m = 1024;
    mat->max_n = 16384;
    mat->m = mat->max_m;
    mat->n = mat->max_n;
    mat->max_size = mat->max_m * mat->max_n;

    mat->me = (double**)calloc(mat->max_m, sizeof(double*));
    mat->base = (double*)calloc(data_size, sizeof(double));
    for (u_int i = 0; i < mat->max_m; i++) {
        mat->me[i] = &mat->base[i * mat->max_n];
    }

    vec->max_dim = mat->max_n;
    vec->dim = vec->max_dim;
    vec->ve = (double*)calloc(vec->max_dim, sizeof(double));

    for (u_int i = 0; i < vec->max_dim; i++) {
        vec->ve[i] = (double)(i & 511);
    }

    row = 512;
    _usr_j0 = 0;
    lim = mat->max_n;

    j = 0;
}