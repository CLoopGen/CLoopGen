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
int i;
int j;
int l;
int n;
int n1;
int lb;
int ilb;
double **Av;
double c;

double **Av_storage;
double *ve_storage;

void init_vars() {
    n = 4096;
    n1 = n - 1;
    lb = 1;
    i = n - 2;
    ilb = i + lb;

    ve_storage = (double*)calloc(n, sizeof(double));
    x = (VEC*)malloc(sizeof(VEC));
    x->dim = n;
    x->max_dim = n;
    x->ve = ve_storage;

    Av_storage = (double**)calloc(n, sizeof(double*));
    for (int idx = 0; idx < n; idx++) {
        Av_storage[idx] = (double*)calloc(n, sizeof(double));
    }
    Av = Av_storage;

    c = 0.0;
}