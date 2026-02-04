#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
double xmean;
double ymean;
size_t nx;
size_t ny;
size_t i;
size_t j;
long double wcovariance;
long double W;

void init_vars() {
    nx = 4096;
    ny = 4096;
    
    xrange_data = (double*)calloc(nx + 1, sizeof(double));
    yrange_data = (double*)calloc(ny + 1, sizeof(double));
    bin_data = (double*)calloc(nx * ny, sizeof(double));
    
    for (size_t idx = 0; idx <= nx; idx++) {
        xrange_data[idx] = idx * 0.5;
    }
    for (size_t idx = 0; idx <= ny; idx++) {
        yrange_data[idx] = idx * 0.3;
    }
    for (size_t idx = 0; idx < nx * ny; idx++) {
        bin_data[idx] = (double)(rand() % 100) / 10.0;
    }
    
    h = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    h->nx = nx;
    h->ny = ny;
    h->xrange = xrange_data;
    h->yrange = yrange_data;
    h->bin = bin_data;
    
    xmean = 1000.0;
    ymean = 800.0;
    
    wcovariance = 0.0;
    W = 0.0;
    
    i = 0;
    j = 0;
}