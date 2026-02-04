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
size_t i;
size_t nx;
size_t ny;

void init_vars() {
    nx = 10000;
    ny = 1000;
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h->nx = nx;
    h->ny = ny;
    h->xrange = (double *)calloc(nx + 1, sizeof(double));
    h->yrange = (double *)calloc(ny + 1, sizeof(double));
    h->bin = (double *)calloc(nx * ny, sizeof(double));
}

// Do not include main or conflicting functions