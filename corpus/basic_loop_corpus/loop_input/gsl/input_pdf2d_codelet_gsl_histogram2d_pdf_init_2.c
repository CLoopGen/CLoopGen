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
size_t n;
double mean;

void init_vars() {
    n = 16777216; // ~134 MB for doubles, targets ~0.01 sec runtime on modern CPU
    mean = 0.0;
    
    h = (gsl_histogram2d*)calloc(1, sizeof(gsl_histogram2d));
    if (!h) exit(1);
    
    h->nx = n;
    h->ny = 1;
    h->xrange = NULL;
    h->yrange = NULL;
    
    h->bin = (double*)malloc(n * sizeof(double));
    if (!h->bin) exit(1);
    
    // Initialize bin values to non-zero to ensure meaningful computation
    for (size_t idx = 0; idx < n; idx++) {
        h->bin[idx] = (double)(idx % 1000) + 1.0;
    }
}