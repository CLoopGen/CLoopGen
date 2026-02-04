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
gsl_histogram2d *h1;
size_t i;
int status;

void init_vars() {
    h = malloc(sizeof(gsl_histogram2d));
    h1 = malloc(sizeof(gsl_histogram2d));

    h->nx = 108;
    h->ny = 1;
    h1->nx = 108;
    h1->ny = 1;

    h->xrange = malloc((h->nx) * sizeof(double));
    h1->xrange = malloc((h1->nx) * sizeof(double));
    h->yrange = malloc((h->ny) * sizeof(double));
    h1->yrange = malloc((h1->ny) * sizeof(double));
    h->bin = malloc((h->nx * h->ny) * sizeof(double));
    h1->bin = malloc((h1->nx * h1->ny) * sizeof(double));

    for (size_t idx = 0; idx < h->nx; idx++) {
        h->xrange[idx] = (double)(idx * 2);
        h1->xrange[idx] = (double)(idx * 2 + 1);
    }

    for (size_t idx = 0; idx < h->ny; idx++) {
        h->yrange[idx] = 1.0;
        h1->yrange[idx] = 1.0;
    }

    for (size_t idx = 0; idx < h->nx * h->ny; idx++) {
        h->bin[idx] = 0.5;
        h1->bin[idx] = 0.6;
    }

    i = 0;
    status = 0;
}