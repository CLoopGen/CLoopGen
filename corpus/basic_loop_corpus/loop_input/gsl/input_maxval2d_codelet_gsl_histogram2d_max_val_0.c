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
size_t nx;
size_t ny;
size_t i;
double max;

void init_vars() {
    nx = 10000;
    ny = 10000;
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h->nx = nx;
    h->ny = ny;
    h->xrange = (double *)calloc(nx + 1, sizeof(double));
    h->yrange = (double *)calloc(ny + 1, sizeof(double));
    h->bin = (double *)malloc(nx * ny * sizeof(double));
    for (size_t idx = 0; idx < nx * ny; idx++) {
        h->bin[idx] = (double)(rand() % 1000) / 10.0;
    }
    max = -1.0;
}