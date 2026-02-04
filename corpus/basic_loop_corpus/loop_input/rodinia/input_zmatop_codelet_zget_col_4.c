#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

int col;
ZMAT *mat;
ZVEC *vec;
u_int i;

void init_vars() {
    const u_int size = 1 << 20; // ~16MB of complex data (each complex is 16 bytes)

    col = 100; // arbitrary column index within bounds

    mat = (ZMAT*)malloc(sizeof(ZMAT));
    vec = (ZVEC*)malloc(sizeof(ZVEC));

    mat->m = size;
    mat->n = 200;
    mat->max_m = size;
    mat->max_n = 200;
    mat->max_size = size * 200;
    mat->base = (complex*)calloc(mat->max_size, sizeof(complex));
    mat->me = (complex**)malloc(mat->m * sizeof(complex*));

    for (u_int idx = 0; idx < mat->m; idx++) {
        mat->me[idx] = &(mat->base[idx * mat->n]);
    }

    vec->dim = size;
    vec->max_dim = size;
    vec->ve = (complex*)malloc(vec->max_dim * sizeof(complex));

    for (u_int idx = 0; idx < vec->dim; idx++) {
        vec->ve[idx].re = 0.0;
        vec->ve[idx].im = 0.0;
    }
}