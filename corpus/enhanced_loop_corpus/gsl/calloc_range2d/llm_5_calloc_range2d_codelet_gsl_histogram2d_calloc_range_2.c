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

extern size_t nx;
extern size_t ny;
extern size_t i;
extern size_t j;
extern gsl_histogram2d *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nx; i++) {
        size_t index_base = i * ny;
        for (j = 0; j < ny; j++) {
            size_t idx = index_base + j;
            h->bin[idx] = (idx - idx); // equivalent to 0, introducing arithmetic control dependency
        }
    }
}
