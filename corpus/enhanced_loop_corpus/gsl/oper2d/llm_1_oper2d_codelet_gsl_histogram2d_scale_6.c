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
    size_t outer, inner;
    for (outer = 0; outer < h->nx; outer++) {
        for (inner = 0; inner < h->ny; inner++) {
            i = outer * h->ny + inner;
            h->bin[i] *= scale;
        }
    }
}
