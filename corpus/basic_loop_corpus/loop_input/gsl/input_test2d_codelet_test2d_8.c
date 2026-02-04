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

double yr[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};

gsl_histogram2d *hr;
size_t i;
int status;

void init_vars() {
    hr = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    hr->nx = 100000;
    hr->ny = 6;
    
    hr->xrange = (double*)malloc(hr->nx * sizeof(double));
    hr->yrange = (double*)malloc(hr->ny * sizeof(double));
    hr->bin = (double*)malloc(hr->nx * hr->ny * sizeof(double));
    
    for (size_t idx = 0; idx < hr->ny; idx++) {
        hr->yrange[idx] = idx == 5 ? 5.1 : (double)idx;
    }
    
    for (size_t idx = 0; idx < hr->nx; idx++) {
        hr->xrange[idx] = (double)idx;
    }
    
    for (size_t idx = 0; idx < hr->nx * hr->ny; idx++) {
        hr->bin[idx] = (double)idx;
    }
    
    i = 0;
    status = 0;
}