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

extern  size_t nx;
extern gsl_histogram2d *h;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *xrange = h->xrange;
    xrange[0] = 0;
    for (i = 1; i < nx + 1; i++) {
        xrange[i] = xrange[i-1] + 1.0;
    }
}
