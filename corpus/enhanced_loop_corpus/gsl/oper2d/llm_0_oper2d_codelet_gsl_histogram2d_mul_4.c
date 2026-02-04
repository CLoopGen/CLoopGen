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
    for (size_t i = 0; i < nx; i++) {
        for (size_t j = 0; j < ny; j++) {
            size_t idx = i * ny + j;
            h1->bin[idx] *= h2->bin[idx];
        }
    }
}
