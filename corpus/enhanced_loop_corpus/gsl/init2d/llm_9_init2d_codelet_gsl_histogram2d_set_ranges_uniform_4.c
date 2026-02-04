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
extern size_t i;
extern  size_t nx;
extern  size_t ny;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t iy = 0; iy < ny; iy++) {
        for (size_t ix = 0; ix < nx; ix++) {
            size_t idx = iy * nx + ix;
            h->bin[idx] = 0.0;
        }
    }
}
