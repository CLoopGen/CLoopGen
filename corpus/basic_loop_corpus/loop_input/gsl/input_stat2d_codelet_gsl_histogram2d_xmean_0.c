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

static double *xrange_data;
static double *yrange_data;
static double *bin_data;
gsl_histogram2d *h;
size_t nx;
size_t ny;
size_t i;
size_t j;
long double wmean;
long double W;

void init_vars() {
    nx = 4096;
    ny = 4096;
    
    h = (gsl_histogram2d *)calloc(1, sizeof(gsl_histogram2d));
    h->nx = nx;
    h->ny = ny;
    
    xrange_data = (double *)calloc(nx + 1, sizeof(double));
    yrange_data = (double *)calloc(ny + 1, sizeof(double));
    bin_data = (double *)calloc(nx * ny, sizeof(double));
    
    h->xrange = xrange_data;
    h->yrange = yrange_data;
    h->bin = bin_data;
    
    for (size_t idx = 0; idx <= nx; idx++) {
        h->xrange[idx] = (double)idx;
    }
    for (size_t idx = 0; idx <= ny; idx++) {
        h->yrange[idx] = (double)idx;
    }
    for (size_t idx = 0; idx < nx * ny; idx++) {
        h->bin[idx] = (idx % 3 == 0) ? 1.0 : 0.0;
    }
    
    i = 0;
    j = 0;
    wmean = 0.0L;
    W = 0.0L;
}