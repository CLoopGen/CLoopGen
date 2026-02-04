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

static double *alloc_and_init_double_array(size_t n) {
    double *arr = (double *)calloc(n, sizeof(double));
    for (size_t i = 0; i < n; i++) {
        arr[i] = (double)(i % 1000) / 10.0;
    }
    return arr;
}

void init_vars() {
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h1 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    g = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));

    h->nx = 107;
    h->ny = 239;
    h1->nx = 107;
    h1->ny = 239;
    g->nx = 107;
    g->ny = 239;

    size_t total_bins = h->nx * h->ny;

    h->xrange = alloc_and_init_double_array(h->nx + 1);
    h->yrange = alloc_and_init_double_array(h->ny + 1);
    h->bin = alloc_and_init_double_array(total_bins);

    h1->xrange = alloc_and_init_double_array(h1->nx + 1);
    h1->yrange = alloc_and_init_double_array(h1->ny + 1);
    h1->bin = alloc_and_init_double_array(total_bins);

    g->xrange = alloc_and_init_double_array(g->nx + 1);
    g->yrange = alloc_and_init_double_array(g->ny + 1);
    g->bin = alloc_and_init_double_array(total_bins);

    for (size_t i = 0; i < total_bins; i++) {
        g->bin[i] = h->bin[i] + h1->bin[i] + 1.0;
    }

    i = 0;
    status = 0;
}