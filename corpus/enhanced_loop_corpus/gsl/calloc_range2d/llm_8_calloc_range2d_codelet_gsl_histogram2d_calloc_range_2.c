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
    size_t stride = 4;
    for (i = 0; i < nx; i++) {
        size_t offset = i * ny;
        for (j = 0; j < ny; j += stride) {
            // Unroll loop by 4 to increase computational intensity per iteration
            h->bin[offset + j] = 0;
            if (j + 1 < ny) h->bin[offset + j + 1] = 0;
            if (j + 2 < ny) h->bin[offset + j + 2] = 0;
            if (j + 3 < ny) h->bin[offset + j + 3] = 0;
        }
    }
}
