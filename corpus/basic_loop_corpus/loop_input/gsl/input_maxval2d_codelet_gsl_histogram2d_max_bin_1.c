#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

gsl_histogram2d *h;
size_t nx = 10000;
size_t ny = 1000;
size_t imax;
size_t jmax;
size_t i;
size_t j;
double max = -__DBL_MAX__;

static double *alloc_and_init_array(size_t n) {
    double *arr = (double *)calloc(n, sizeof(double));
    if (!arr) exit(1);
    for (size_t idx = 0; idx < n; idx++) {
        arr[idx] = (double)(rand() % 10000) / 10.0;
    }
    return arr;
}

void init_vars() {
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    if (!h) exit(1);

    h->nx = nx;
    h->ny = ny;
    h->xrange = alloc_and_init_array(nx + 1);
    h->yrange = alloc_and_init_array(ny + 1);
    h->bin = alloc_and_init_array(nx * ny);

    max = -__DBL_MAX__;
    imax = 0;
    jmax = 0;
    i = 0;
    j = 0;
}