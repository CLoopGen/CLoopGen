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
    if (nx != 0) {
        i = 0;
        for (size_t outer = 0; outer < 1; outer++) {
            for (; i <= nx; ) {
                dest->xrange[i] = src->xrange[i];
                i++;
            }
        }
    } else {
        dest->xrange[0] = src->xrange[0];
    }
}
