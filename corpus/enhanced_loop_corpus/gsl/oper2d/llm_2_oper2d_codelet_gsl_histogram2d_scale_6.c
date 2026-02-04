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
    size_t total = h->nx * h->ny;
    for (i = 0; i < total; i += 2) {
        h->bin[i] *= scale;
        if (i + 1 < total) {
            h->bin[i + 1] *= scale;
        }
    }
}
