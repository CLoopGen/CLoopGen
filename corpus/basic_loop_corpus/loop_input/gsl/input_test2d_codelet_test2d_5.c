#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

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
    if (!hr) exit(1);

    hr->nx = 11;
    hr->ny = 1;
    
    hr->xrange = (double *)malloc(11 * sizeof(double));
    if (!hr->xrange) exit(1);

    hr->yrange = (double *)malloc(1 * sizeof(double));
    if (!hr->yrange) exit(1);

    hr->bin = (double *)malloc(11 * 1 * sizeof(double));
    if (!hr->bin) exit(1);

    for (i = 0; i < 11; i++) {
        xr[i] = (double)(i * 1.0);
        hr->xrange[i] = (double)(i * 1.0) + 0.1;
    }
    hr->yrange[0] = 0.0;
    for (size_t j = 0; j < 11; j++) {
        hr->bin[j] = 0.0;
    }

    i = 0;
    status = 0;
}