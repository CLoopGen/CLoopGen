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

extern  gsl_histogram2d *src;
extern size_t nx;
extern size_t ny;
extern size_t i;
extern gsl_histogram2d *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nx * ny > 0) {
        size_t i = 0;
        for (; i < nx * ny - 1; i += 2) {
            h->bin[i] = src->bin[i];
            h->bin[i + 1] = src->bin[i + 1];
        }
        if (i < nx * ny) {
            h->bin[i] = src->bin[i];
        }
    }
}
