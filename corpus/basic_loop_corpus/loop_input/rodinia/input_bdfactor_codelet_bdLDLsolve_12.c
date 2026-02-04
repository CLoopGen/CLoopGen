#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *b;
VEC *x;
int i;
int j;
int l;
int n;
int lb;
int ilb;
double **Av;
double c;

static double **Av_storage;
static double *b_ve_storage;
static double *x_ve_storage;

void init_vars() {
    n = 2000;
    lb = 10;
    ilb = 0;
    c = 0.0;

    b = (VEC*)malloc(sizeof(VEC));
    x = (VEC*)malloc(sizeof(VEC));

    b->dim = n;
    b->max_dim = n;
    b->ve = b_ve_storage = (double*)calloc(n, sizeof(double));

    x->dim = n;
    x->max_dim = n;
    x->ve = x_ve_storage = (double*)calloc(n, sizeof(double));

    Av_storage = (double**)malloc((n + lb) * sizeof(double*));
    for (int l_idx = 0; l_idx < n + lb; l_idx++) {
        Av_storage[l_idx] = (double*)malloc(n * sizeof(double));
        for (int j_idx = 0; j_idx < n; j_idx++) {
            Av_storage[l_idx][j_idx] = 1.0 / (1.0 + abs(l_idx - j_idx));
        }
    }
    Av = Av_storage;

    for (int idx = 0; idx < n; idx++) {
        b->ve[idx] = 1.0 * idx;
        x->ve[idx] = 0.0;
    }
}