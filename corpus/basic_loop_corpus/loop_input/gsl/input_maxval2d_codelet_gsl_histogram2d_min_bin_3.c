#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

gsl_histogram2d *h;
size_t nx;
size_t ny;
size_t imin;
size_t jmin;
size_t i;
size_t j;
double min;

void init_vars() {
    nx = 5000;
    ny = 5000;
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h->nx = nx;
    h->ny = ny;
    h->xrange = (double *)malloc((nx + 1) * sizeof(double));
    h->yrange = (double *)malloc((ny + 1) * sizeof(double));
    h->bin = (double *)malloc(nx * ny * sizeof(double));

    for (size_t idx = 0; idx < nx + 1; idx++) {
        h->xrange[idx] = (double)idx;
    }
    for (size_t idx = 0; idx < ny + 1; idx++) {
        h->yrange[idx] = (double)idx;
    }
    for (size_t idx = 0; idx < nx * ny; idx++) {
        h->bin[idx] = (double)(idx % 1000) - 500.0;
    }

    min = 1e300;
    imin = 0;
    jmin = 0;
    i = 0;
    j = 0;
}