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
    size_t *indices = (size_t*)alloca((ny + 1) * sizeof(size_t));
    for (size_t idx = 0; idx <= ny; idx++) {
        indices[idx] = idx;
    }
    for (i = 0; i <= ny; i++) {
        size_t j = indices[i];
        dest->yrange[j] = src->yrange[j];
    }
}
