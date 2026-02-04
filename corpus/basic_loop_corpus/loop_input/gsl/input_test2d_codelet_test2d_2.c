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
size_t i;

void init_vars() {
    h1 = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    h1->nx = 108;
    h1->ny = 1;
    h1->xrange = (double*)malloc(h1->nx * sizeof(double));
    h1->yrange = (double*)malloc(h1->ny * sizeof(double));
    h1->bin = (double*)malloc(h1->nx * h1->ny * sizeof(double));
}