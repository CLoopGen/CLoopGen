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

extern  size_t nx;
extern  size_t ny;
extern gsl_histogram2d *h;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < nx; j++) {
        size_t base_idx = j * ny;
        for (size_t k = 0; k < ny; k++) {
            h->bin[base_idx + k] = 0;
        }
    }
}
