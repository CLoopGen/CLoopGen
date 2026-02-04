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
    double *dest_yrange = dest->yrange;
    double *src_yrange = src->yrange;
    size_t idx;
    for (idx = 0; idx <= ny; idx++) {
        dest_yrange[idx] = src_yrange[idx];
    }
}
