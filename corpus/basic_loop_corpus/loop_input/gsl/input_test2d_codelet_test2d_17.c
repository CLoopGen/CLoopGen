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

static double *alloc_bin(size_t size) {
    double *bin = (double *)calloc(size, sizeof(double));
    if (!bin) exit(1);
    return bin;
}

void init_vars() {
    size_t total_bins = 107 * 239;
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h1 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    g = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));

    if (!h || !h1 || !g) exit(1);

    h->nx = 107;
    h->ny = 239;
    h1->nx = 107;
    h1->ny = 239;
    g->nx = 107;
    g->ny = 239;

    h->xrange = (double *)calloc(h->nx + 1, sizeof(double));
    h->yrange = (double *)calloc(h->ny + 1, sizeof(double));
    h->bin = alloc_bin(total_bins);

    h1->xrange = (double *)calloc(h1->nx + 1, sizeof(double));
    h1->yrange = (double *)calloc(h1->ny + 1, sizeof(double));
    h1->bin = alloc_bin(total_bins);

    g->xrange = (double *)calloc(g->nx + 1, sizeof(double));
    g->yrange = (double *)calloc(g->ny + 1, sizeof(double));
    g->bin = alloc_bin(total_bins);

    for (size_t idx = 0; idx < total_bins; idx++) {
        h->bin[idx] = 1.0 + 0.01 * (idx % 100);
        g->bin[idx] = 2.0 + 0.02 * (idx % 80);
        h1->bin[idx] = g->bin[idx] * h->bin[idx];
    }

    i = 0;
    status = 0;
}