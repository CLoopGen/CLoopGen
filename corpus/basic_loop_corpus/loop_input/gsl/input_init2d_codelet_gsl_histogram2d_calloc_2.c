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

size_t ny = 10000000; // ~80 MB for yrange array (10M doubles)
gsl_histogram2d *h;
size_t i;

void init_vars() {
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    if (!h) exit(1);

    h->nx = 0;
    h->ny = ny;

    h->xrange = NULL;

    h->yrange = (double *)malloc((ny + 1) * sizeof(double));
    if (!h->yrange) exit(1);

    h->bin = NULL;
}