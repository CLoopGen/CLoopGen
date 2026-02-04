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

extern gsl_histogram2d *h;
extern double shift;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t total_iters = (h->nx) * (h->ny) * 4;
    for (i = 0; i < total_iters; i++) {
        size_t idx = i % (h->nx * h->ny);
        h->bin[idx] += shift * 0.25;
    }
}
