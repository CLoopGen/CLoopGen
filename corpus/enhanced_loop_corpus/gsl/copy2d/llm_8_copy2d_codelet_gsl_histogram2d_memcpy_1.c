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
extern size_t ny;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= ny; i += 2) {
        if (i <= ny) {
            dest->yrange[i] = src->yrange[i];
        }
        if (i + 1 <= ny) {
            dest->yrange[i + 1] = src->yrange[i + 1];
        }
    }
}
