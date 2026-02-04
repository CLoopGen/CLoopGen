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
    for (size_t j = 0; j < h->nx * h->ny; j += 2) {
        h->bin[j] += shift;
        if (j + 1 < h->nx * h->ny) {
            h->bin[j + 1] += shift;
        }
    }
}
