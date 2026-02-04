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
    h1 = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    h2 = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));

    h1->nx = 5000;
    h1->ny = 5000;
    size_t total_size = h1->nx * h1->ny;

    h2->nx = h1->nx;
    h2->ny = h1->ny;

    h1->xrange = (double*)calloc(h1->nx + 1, sizeof(double));
    h1->yrange = (double*)calloc(h1->ny + 1, sizeof(double));
    h1->bin = (double*)calloc(total_size, sizeof(double));

    h2->xrange = (double*)calloc(h2->nx + 1, sizeof(double));
    h2->yrange = (double*)calloc(h2->ny + 1, sizeof(double));
    h2->bin = (double*)calloc(total_size, sizeof(double));

    for (size_t j = 0; j < total_size; j++) {
        h2->bin[j] = 1.0;
        h1->bin[j] = 0.0;
    }
}