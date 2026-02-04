#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *x;
VEC *out;
int i;
int j;
int j_end;
int k;
int start_idx;
int end_idx;
int n;
int m;
double **A_me;
double *x_ve;
double sum;

void init_vars() {
    n = 4000;
    m = 500;
    start_idx = -100;
    end_idx = m + 100;

    x = (VEC *)malloc(sizeof(VEC));
    x->dim = m;
    x->max_dim = m;
    x->ve = (double *)calloc(m, sizeof(double));

    out = (VEC *)malloc(sizeof(VEC));
    out->dim = n;
    out->max_dim = n;
    out->ve = (double *)calloc(n, sizeof(double));

    A_me = (double **)calloc(m, sizeof(double *));
    for (int idx = 0; idx < m; idx++) {
        A_me[idx] = (double *)calloc(m, sizeof(double));
        for (int jdx = 0; jdx < m; jdx++) {
            A_me[idx][jdx] = (double)(idx + jdx) / (m + n);
        }
    }

    for (int idx = 0; idx < m; idx++) {
        x->ve[idx] = (double)idx / m;
    }

    i = 0;
    j = 0;
    j_end = 0;
    k = 0;
    x_ve = NULL;
    sum = 0.0;
}