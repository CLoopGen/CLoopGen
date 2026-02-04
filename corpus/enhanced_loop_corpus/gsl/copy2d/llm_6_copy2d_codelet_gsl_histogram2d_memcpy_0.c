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
    double *dest_xrange = dest->xrange;
    double *src_xrange = src->xrange;
    size_t idx = 0;
    for (i = 0; i <= nx; i++) {
        dest_xrange[idx] = src_xrange[idx];
        idx++;
    }
}
