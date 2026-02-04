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

void init_vars() {
    h1 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    g = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));

    h1->nx = 107;
    h1->ny = 239;
    g->nx = 107;
    g->ny = 239;

    size_t total_elements = h1->nx * h1->ny;

    h1->xrange = (double *)malloc((h1->nx + 1) * sizeof(double));
    h1->yrange = (double *)malloc((h1->ny + 1) * sizeof(double));
    h1->bin = (double *)malloc(total_elements * sizeof(double));

    g->xrange = (double *)malloc((g->nx + 1) * sizeof(double));
    g->yrange = (double *)malloc((g->ny + 1) * sizeof(double));
    g->bin = (double *)malloc(total_elements * sizeof(double));

    for (size_t idx = 0; idx < total_elements; idx++) {
        h1->bin[idx] = 1.0;
        g->bin[idx] = 2.0;
    }

    for (size_t idx = 0; idx < h1->nx + 1; idx++) {
        h1->xrange[idx] = idx * 0.1;
        g->xrange[idx] = idx * 0.1;
    }
    for (size_t idx = 0; idx < h1->ny + 1; idx++) {
        h1->yrange[idx] = idx * 0.1;
        g->yrange[idx] = idx * 0.1;
    }

    i = 0;
    status = 0;
}