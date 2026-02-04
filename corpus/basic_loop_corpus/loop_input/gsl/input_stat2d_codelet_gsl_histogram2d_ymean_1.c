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
    nx = 1000;
    ny = 1000;
    
    h = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    if (!h) exit(1);
    
    xrange_data = (double*)calloc(nx + 1, sizeof(double));
    yrange_data = (double*)calloc(ny + 1, sizeof(double));
    bin_data = (double*)calloc(nx * ny, sizeof(double));
    
    if (!xrange_data || !yrange_data || !bin_data) exit(1);
    
    for (size_t idx = 0; idx <= nx; idx++) {
        xrange_data[idx] = (double)idx;
    }
    for (size_t idx = 0; idx <= ny; idx++) {
        yrange_data[idx] = (double)idx;
    }
    
    for (size_t i_idx = 0; i_idx < nx; i_idx++) {
        for (size_t j_idx = 0; j_idx < ny; j_idx++) {
            size_t idx = i_idx * ny + j_idx;
            bin_data[idx] = (i_idx * 7 + j_idx * 13) % 100 == 0 ? 1.0 : 0.0;
        }
    }
    
    h->nx = nx;
    h->ny = ny;
    h->xrange = xrange_data;
    h->yrange = yrange_data;
    h->bin = bin_data;
    
    wmean = 0.0L;
    W = 0.0L;
    i = 0;
    j = 0;
}