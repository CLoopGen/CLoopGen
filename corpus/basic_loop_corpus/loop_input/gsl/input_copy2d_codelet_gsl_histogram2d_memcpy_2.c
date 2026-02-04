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

gsl_histogram2d *dest;
gsl_histogram2d *src;
size_t nx;
size_t ny;
size_t i;

void init_vars() {
    nx = 8192;
    ny = 4096;
    size_t total_elements = nx * ny;
    size_t bin_size_bytes = total_elements * sizeof(double);

    dest = (gsl_histogram2d *)calloc(1, sizeof(gsl_histogram2d));
    src = (gsl_histogram2d *)calloc(1, sizeof(gsl_histogram2d));

    dest->nx = nx;
    dest->ny = ny;
    src->nx = nx;
    src->ny = ny;

    dest->xrange = (double *)calloc(nx + 1, sizeof(double));
    dest->yrange = (double *)calloc(ny + 1, sizeof(double));
    dest->bin = (double *)calloc(total_elements, sizeof(double));

    src->xrange = (double *)calloc(nx + 1, sizeof(double));
    src->yrange = (double *)calloc(ny + 1, sizeof(double));
    src->bin = (double *)calloc(total_elements, sizeof(double));

    for (size_t idx = 0; idx < total_elements; idx++) {
        src->bin[idx] = (double)(idx % 1000) / 3.14;
    }
}