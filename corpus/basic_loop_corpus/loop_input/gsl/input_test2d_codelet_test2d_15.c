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
gsl_histogram2d *g;
size_t i;
int status;

static double *alloc_initialized_double_array(size_t n) {
    double *arr = (double *)calloc(n, sizeof(double));
    for (size_t i = 0; i < n; ++i) {
        arr[i] = (double)(i % 17); // arbitrary non-zero pattern
    }
    return arr;
}

void init_vars() {
    const size_t nx = 107;
    const size_t ny = 239;
    const size_t total_bins = nx * ny;

    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h1 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    g = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));

    h->nx = nx;
    h->ny = ny;
    h1->nx = nx;
    h1->ny = ny;
    g->nx = nx;
    g->ny = ny;

    h->xrange = alloc_initialized_double_array(nx + 1);
    h->yrange = alloc_initialized_double_array(ny + 1);
    h->bin = alloc_initialized_double_array(total_bins);

    h1->xrange = alloc_initialized_double_array(nx + 1);
    h1->yrange = alloc_initialized_double_array(ny + 1);
    h1->bin = alloc_initialized_double_array(total_bins);

    g->xrange = alloc_initialized_double_array(nx + 1);
    g->yrange = alloc_initialized_double_array(ny + 1);
    g->bin = alloc_initialized_double_array(total_bins);

    for (size_t i = 0; i < total_bins; ++i) {
        h1->bin[i] = g->bin[i] + h->bin[i];
    }

    // Introduce one mismatch to trigger status = 1
    if (total_bins > 0) {
        h1->bin[total_bins - 1] += 1.0;
    }

    i = 0;
    status = 0;
}