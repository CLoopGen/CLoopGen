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
    for (size_t i = 0; i < nx * ny; i += 2) {
        h->bin[i] = 0;
        if (i + 1 < nx * ny) {
            h->bin[i + 1] = 0;
        }
    }
}
