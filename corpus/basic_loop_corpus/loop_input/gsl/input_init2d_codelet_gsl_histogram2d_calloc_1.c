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

size_t nx;
gsl_histogram2d *h;
size_t i;

void init_vars() {
    nx = 16777216; // ~16.7M elements, aiming for ~0.01 sec runtime on modern CPU

    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    if (!h) exit(1);

    h->nx = nx;
    h->ny = 1;
    h->xrange = (double *)malloc((nx + 1) * sizeof(double));
    h->yrange = (double *)malloc((h->ny + 1) * sizeof(double));
    h->bin = (double *)malloc(nx * h->ny * sizeof(double));

    if (!h->xrange || !h->yrange || !h->bin) exit(1);
}