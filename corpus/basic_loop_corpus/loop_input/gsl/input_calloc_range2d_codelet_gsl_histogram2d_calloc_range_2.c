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

size_t nx = 512;
size_t ny = 512;
size_t i;
size_t j;
gsl_histogram2d *h;

void init_vars() {
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h->nx = nx;
    h->ny = ny;

    h->xrange = (double *)calloc(nx + 1, sizeof(double));
    h->yrange = (double *)calloc(ny + 1, sizeof(double));
    h->bin = (double *)calloc(nx * ny, sizeof(double));
}