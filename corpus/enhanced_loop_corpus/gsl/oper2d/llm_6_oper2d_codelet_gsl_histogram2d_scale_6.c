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
extern double scale;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t idx;
    double *bin_ptr = h->bin;
    for (i = 0; i < (h->nx) * (h->ny); i++) {
        idx = i;
        bin_ptr[idx] *= scale;
    }
}
