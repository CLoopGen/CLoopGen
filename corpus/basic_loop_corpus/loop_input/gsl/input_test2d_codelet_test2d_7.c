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

double xr[11];

gsl_histogram2d *hr;
size_t i;
int status;

void init_vars() {
    hr = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    if (!hr) {
        exit(1);
    }

    hr->nx = 11;
    hr->ny = 1;
    hr->xrange = (double *)malloc(11 * sizeof(double));
    hr->yrange = (double *)malloc(2 * sizeof(double));
    hr->bin = (double *)malloc(11 * 1 * sizeof(double));

    if (!hr->xrange || !hr->yrange || !hr->bin) {
        exit(1);
    }

    for (i = 0; i < 11; i++) {
        xr[i] = (double)(i * 10);
        hr->xrange[i] = (double)(i * 10);
    }

    for (i = 0; i < 2; i++) {
        hr->yrange[i] = (double)(i * 5);
    }

    for (i = 0; i < 11; i++) {
        hr->bin[i] = 0.0;
    }

    i = 0;
    status = 0;
}