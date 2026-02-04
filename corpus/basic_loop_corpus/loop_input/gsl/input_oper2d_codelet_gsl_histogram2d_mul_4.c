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
gsl_histogram2d *h2;
size_t i;

void init_vars() {
    h1 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h2 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));

    h1->nx = 8000;
    h1->ny = 8000;
    size_t total_elements = h1->nx * h1->ny;

    h1->xrange = (double *)calloc(h1->nx + 1, sizeof(double));
    h1->yrange = (double *)calloc(h1->ny + 1, sizeof(double));
    h1->bin = (double *)malloc(total_elements * sizeof(double));

    h2->nx = h1->nx;
    h2->ny = h1->ny;
    h2->xrange = (double *)calloc(h2->nx + 1, sizeof(double));
    h2->yrange = (double *)calloc(h2->ny + 1, sizeof(double));
    h2->bin = (double *)malloc(total_elements * sizeof(double));

    for (size_t idx = 0; idx < total_elements; idx++) {
        h1->bin[idx] = 1.0 + 0.01 * (idx % 100);
        h2->bin[idx] = 2.0 + 0.02 * (idx % 100);
    }
}