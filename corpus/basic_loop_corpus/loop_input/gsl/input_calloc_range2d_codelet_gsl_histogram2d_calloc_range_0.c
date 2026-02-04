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

size_t nx = 1000000;
double *xrange;
size_t i;
gsl_histogram2d *h;

void init_vars() {
    xrange = (double *)calloc(nx + 1, sizeof(double));
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h->nx = nx;
    h->xrange = (double *)malloc((nx + 1) * sizeof(double));
}