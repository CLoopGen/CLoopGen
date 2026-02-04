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

extern gsl_histogram2d *dest;
extern  gsl_histogram2d *src;
extern size_t nx;
extern size_t ny;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nx * ny; i++) {
        if (i >= nx) {  // Skip first row (first nx elements)
            dest->bin[i] = src->bin[i];
        }
    }
}
