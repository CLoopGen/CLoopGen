#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

ZVEC *x;
VEC *scale;
int i;
int dim;
double s;
double sum;

void init_vars() {
    dim = 1 << 20; // Approximately 1M elements for ~0.01 sec runtime

    x = (ZVEC *)malloc(sizeof(ZVEC));
    scale = (VEC *)malloc(sizeof(VEC));

    x->dim = dim;
    x->max_dim = dim;
    x->ve = (complex *)malloc(dim * sizeof(complex));

    scale->dim = dim;
    scale->max_dim = dim;
    scale->ve = (double *)malloc(dim * sizeof(double));

    for (int j = 0; j < dim; j++) {
        x->ve[j].re = 1.0;
        x->ve[j].im = 1.0;
        scale->ve[j] = (j % 2) ? 2.0 : 0.0;
    }

    i = 0;
    s = 0.0;
    sum = 0.0;
}