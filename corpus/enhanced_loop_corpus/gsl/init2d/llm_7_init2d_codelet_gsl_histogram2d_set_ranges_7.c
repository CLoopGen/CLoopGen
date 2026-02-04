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
    size_t *indices = (size_t*)alloca(nx * ny * sizeof(size_t));
    for (size_t idx = 0; idx < nx * ny; idx++) {
        indices[idx] = idx;
    }
    for (size_t idx = 0; idx < nx * ny; idx++) {
        h->bin[indices[idx]] = 0;
    }
}
