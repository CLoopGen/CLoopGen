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
double scale;
size_t i;

void init_vars() {
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h->nx = 5000;
    h->ny = 5000;
    size_t total_bins = h->nx * h->ny;

    h->xrange = (double *)calloc(h->nx + 1, sizeof(double));
    h->yrange = (double *)calloc(h->ny + 1, sizeof(double));
    h->bin = (double *)malloc(total_bins * sizeof(double));

    for (size_t idx = 0; idx < total_bins; idx++) {
        h->bin[idx] = 1.0 + (idx % 100) * 0.01;
    }

    scale = 1.5;

    i = 0;
}