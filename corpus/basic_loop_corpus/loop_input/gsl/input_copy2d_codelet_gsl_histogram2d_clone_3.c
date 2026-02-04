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

gsl_histogram2d *src;
size_t nx = 10000;
size_t ny = 10000;
size_t i;
gsl_histogram2d *h;

void init_vars() {
    src = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    h = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));

    src->nx = nx;
    src->ny = ny;
    h->nx = nx;
    h->ny = ny;

    src->xrange = (double*)calloc(nx + 1, sizeof(double));
    src->yrange = (double*)calloc(ny + 1, sizeof(double));
    h->xrange = (double*)calloc(nx + 1, sizeof(double));
    h->yrange = (double*)calloc(ny + 1, sizeof(double));

    src->bin = (double*)malloc(nx * ny * sizeof(double));
    h->bin = (double*)malloc(nx * ny * sizeof(double));

    for (size_t idx = 0; idx < nx * ny; idx++) {
        src->bin[idx] = (double)(idx % 1000) / 10.0;
    }
}