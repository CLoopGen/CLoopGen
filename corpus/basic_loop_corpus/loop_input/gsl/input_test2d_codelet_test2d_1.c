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

gsl_histogram2d *hr;
size_t i;

static double *create_double_array(size_t n) {
    double *arr = (double *)calloc(n, sizeof(double));
    return arr;
}

void init_vars() {
    hr = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    hr->nx = 10;
    hr->ny = 10;
    hr->xrange = create_double_array(hr->nx + 1);
    hr->yrange = create_double_array(hr->ny + 1);
    hr->bin = create_double_array(hr->nx * hr->ny);
}

// Do not include main or extra headers/comments as per instructions