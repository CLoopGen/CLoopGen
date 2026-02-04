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

gsl_histogram2d *h1;
gsl_histogram2d *g;
size_t i;
int status;

static double *alloc_initialized_double_array(size_t n) {
    double *arr = (double *)calloc(n, sizeof(double));
    for (size_t idx = 0; idx < n; idx++) {
        arr[idx] = (double)(idx % 1000) / 1000.0;
    }
    return arr;
}

void init_vars() {
    h1 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    g = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));

    h1->nx = 107;
    h1->ny = 239;
    g->nx = 107;
    g->ny = 239;

    size_t total_bins = h1->nx * h1->ny;

    h1->xrange = (double *)calloc(h1->nx + 1, sizeof(double));
    h1->yrange = (double *)calloc(h1->ny + 1, sizeof(double));
    g->xrange = (double *)calloc(g->nx + 1, sizeof(double));
    g->yrange = (double *)calloc(g->ny + 1, sizeof(double));

    h1->bin = alloc_initialized_double_array(total_bins);
    g->bin = alloc_initialized_double_array(total_bins);

    i = 0;
    status = 0;
}