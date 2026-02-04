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

static double *bin_data;
static gsl_histogram2d h_store;
gsl_histogram2d *h = &h_store;
size_t i;
size_t nx;
size_t ny;

void init_vars() {
    nx = 10000;
    ny = 100;
    h->nx = nx;
    h->ny = ny;

    h->xrange = NULL;
    h->yrange = NULL;

    bin_data = (double *)calloc(nx * ny, sizeof(double));
    h->bin = bin_data;
}

void cleanup_vars() {
    if (bin_data) {
        free(bin_data);
        bin_data = NULL;
    }
}