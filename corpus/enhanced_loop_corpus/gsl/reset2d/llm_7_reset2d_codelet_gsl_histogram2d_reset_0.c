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
    size_t i1, i2;
    for (i1 = 0; i1 < nx; i1++) {
        for (i2 = 0; i2 < ny; i2++) {
            size_t idx = i1 * ny + i2;
            h->bin[idx] = 0;
        }
    }
}
