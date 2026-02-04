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

static double *dest_yrange;
static double *src_yrange;
static gsl_histogram2d dest_instance;
static gsl_histogram2d src_instance;

gsl_histogram2d *dest = &dest_instance;
gsl_histogram2d *src = &src_instance;
size_t ny;
size_t i;

void init_vars() {
    ny = 1000000; // Enough to take ~0.01s on modern CPU

    dest->ny = ny;
    src->ny = ny;

    dest_yrange = (double*)calloc(ny + 1, sizeof(double));
    src_yrange = (double*)calloc(ny + 1, sizeof(double));

    if (!dest_yrange || !src_yrange) {
        exit(1);
    }

    for (size_t j = 0; j <= ny; j++) {
        src_yrange[j] = (double)(j % 1000) + 0.5;
    }

    dest->yrange = dest_yrange;
    src->yrange = src_yrange;
}