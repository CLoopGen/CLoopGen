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
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    for (i = 0; i <= nx; i += stride) {
        if (i <= nx) dest->xrange[i] = src->xrange[i];
    }
    // Handle the last element if nx is not aligned with the stride
    if ((nx % 2) == 1 && nx > 0) {
        dest->xrange[nx] = src->xrange[nx];
    }
}
