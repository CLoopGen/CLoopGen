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
size_t i;
size_t j;
size_t k;
int status;

static double *bin_data;
static gsl_histogram2d h_storage;

void init_vars() {
    h = &h_storage;
    h->nx = 107;
    h->ny = 239;
    
    bin_data = (double*)malloc(h->nx * h->ny * sizeof(double));
    if (!bin_data) {
        exit(1);
    }
    
    k = 0;
    for (i = 0; i < h->nx; i++) {
        for (j = 0; j < h->ny; j++) {
            k++;
            bin_data[i * 239 + j] = (double)k;
        }
    }
    k = 0;
    
    h->xrange = (double*)malloc((h->nx + 1) * sizeof(double));
    h->yrange = (double*)malloc((h->ny + 1) * sizeof(double));
    h->bin = bin_data;
    
    if (!h->xrange || !h->yrange) {
        exit(1);
    }
    
    for (i = 0; i <= h->nx; i++) {
        h->xrange[i] = (double)i;
    }
    for (j = 0; j <= h->ny; j++) {
        h->yrange[j] = (double)j;
    }
    
    status = 0;
}