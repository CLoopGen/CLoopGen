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
double xmean;
size_t nx = 1000;
size_t ny = 1000;
size_t i;
size_t j;
long double wvariance = 0.0L;
long double W = 0.0L;

void init_vars() {
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h->nx = nx;
    h->ny = ny;

    h->xrange = (double *)malloc((nx + 1) * sizeof(double));
    h->yrange = (double *)malloc((ny + 1) * sizeof(double));
    h->bin = (double *)malloc(nx * ny * sizeof(double));

    for (size_t idx = 0; idx <= nx; idx++) {
        h->xrange[idx] = (double)(idx * 2);
    }
    for (size_t idx = 0; idx <= ny; idx++) {
        h->yrange[idx] = (double)(idx * 3);
    }
    for (size_t idx = 0; idx < nx * ny; idx++) {
        h->bin[idx] = (double)(rand() % 100) / 10.0;
    }

    xmean = 1000.0;
    wvariance = 0.0L;
    W = 0.0L;
}