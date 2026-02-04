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
size_t i;

void init_vars() {
    nx = 10000000; // ~80 MB for two double arrays (nx+1 elements each), aiming for ~0.01 sec on modern CPU

    dest = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    src = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));

    dest->nx = nx;
    src->nx = nx;

    dest->xrange = (double*)malloc((nx + 1) * sizeof(double));
    src->xrange = (double*)malloc((nx + 1) * sizeof(double));

    dest->yrange = NULL;
    dest->bin = NULL;
    src->yrange = NULL;
    src->bin = NULL;

    for (size_t j = 0; j <= nx; j++) {
        src->xrange[j] = (double)(j % 1000) / 100.0;
    }

    i = 0;
}