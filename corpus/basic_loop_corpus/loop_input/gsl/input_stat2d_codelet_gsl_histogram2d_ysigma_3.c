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
double ymean;
size_t nx = 1000;
size_t ny = 1000;
size_t i;
size_t j;
long double wvariance;
long double W;

static double *xrange_data;
static double *yrange_data;
static double *bin_data;

void init_vars() {
    ymean = 5.0;
    wvariance = 0.0L;
    W = 0.0L;

    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    if (!h) exit(1);

    h->nx = nx;
    h->ny = ny;

    xrange_data = (double *)calloc(nx + 1, sizeof(double));
    yrange_data = (double *)calloc(ny + 1, sizeof(double));
    bin_data = (double *)calloc(nx * ny, sizeof(double));

    if (!xrange_data || !yrange_data || !bin_data) exit(1);

    for (size_t idx = 0; idx <= nx; idx++) {
        xrange_data[idx] = idx * 0.1;
    }
    for (size_t idx = 0; idx <= ny; idx++) {
        yrange_data[idx] = idx * 0.1;
    }
    for (size_t idx = 0; idx < nx * ny; idx++) {
        bin_data[idx] = (idx % 13) * 0.01;
    }

    h->xrange = xrange_data;
    h->yrange = yrange_data;
    h->bin = bin_data;
}