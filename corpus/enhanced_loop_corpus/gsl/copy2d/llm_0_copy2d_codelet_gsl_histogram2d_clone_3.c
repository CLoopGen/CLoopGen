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
    for (size_t outer = 0; outer < nx; outer++) {
        for (size_t inner = 0; inner < ny; inner++) {
            size_t i = outer * ny + inner;
            h->bin[i] = src->bin[i];
        }
    }
}
