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

gsl_histogram2d *h;
gsl_histogram2d *h1;
size_t i;
int status;

void init_vars() {
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h1 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));

    h->ny = 240;
    h1->ny = 240;

    h->yrange = (double *)malloc((h->ny) * sizeof(double));
    h1->yrange = (double *)malloc((h1->ny) * sizeof(double));

    for (size_t idx = 0; idx < h->ny; idx++) {
        h->yrange[idx] = (double)(idx * 2);
        h1->yrange[idx] = (double)(idx * 2 + (idx == 120 ? 1 : 0));
    }

    h->nx = 100;
    h1->nx = 100;
    h->xrange = (double *)calloc(h->nx, sizeof(double));
    h1->xrange = (double *)calloc(h1->nx, sizeof(double));
    h->bin = (double *)calloc(h->nx * h->ny, sizeof(double));
    h1->bin = (double *)calloc(h1->nx * h1->ny, sizeof(double));

    i = 0;
    status = 0;
}