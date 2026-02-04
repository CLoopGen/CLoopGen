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
size_t i;
double min = __DBL_MAX__;

void init_vars() {
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h->nx = nx;
    h->ny = ny;
    h->xrange = (double *)calloc(nx + 1, sizeof(double));
    h->yrange = (double *)calloc(ny + 1, sizeof(double));
    h->bin = (double *)malloc(nx * ny * sizeof(double));

    for (size_t idx = 0; idx < nx * ny; idx++) {
        h->bin[idx] = (double)rand() / RAND_MAX * 100.0;
    }

    min = h->bin[0];
    for (size_t idx = 1; idx < nx * ny; idx++) {
        if (h->bin[idx] < min) {
            min = h->bin[idx];
        }
    }
    min += 1.0;
}