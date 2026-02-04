#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

MAT *mat;
MAT *out;
u_int i;
u_int k;
double c;
double s;
u_int j;
double temp;

void init_vars() {
    mat = (MAT*)malloc(sizeof(MAT));
    out = (MAT*)malloc(sizeof(MAT));

    mat->m = 8000;
    mat->n = 2;
    mat->max_m = mat->m;
    mat->max_n = mat->n;
    mat->max_size = mat->m * mat->n;
    
    out->m = mat->m;
    out->n = mat->n;
    out->max_m = out->m;
    out->max_n = out->n;
    out->max_size = out->m * out->n;

    out->base = (double*)calloc(out->m * out->n, sizeof(double));
    out->me = (double**)malloc(out->m * sizeof(double*));
    for (u_int idx = 0; idx < out->m; idx++) {
        out->me[idx] = &(out->base[idx * out->n]);
    }

    i = 0;
    k = 1;
    if (i >= out->n || k >= out->n) {
        i = 0;
        k = 1;
    }

    double angle = 0.7853981633974483; // ~pi/4
    c = cos(angle);
    s = sin(angle);

    for (u_int idx_j = 0; idx_j < out->m; idx_j++) {
        out->me[idx_j][i] = (double)(idx_j + 1);
        out->me[idx_j][k] = (double)(-(idx_j + 1));
    }
}