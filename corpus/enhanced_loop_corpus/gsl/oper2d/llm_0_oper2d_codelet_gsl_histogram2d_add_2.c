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

extern gsl_histogram2d *h1;
extern  gsl_histogram2d *h2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t nx = h1->nx;
    size_t ny = h1->ny;
    for (size_t j = 0; j < nx; j++) {
        for (size_t k = 0; k < ny; k++) {
            size_t idx = j * ny + k;
            h1->bin[idx] += h2->bin[idx];
        }
    }
}
