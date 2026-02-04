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
    // Variant 2: Strided memory access using a single loop with stride equal to ny
    size_t idx;
    for (idx = 0; idx < nx * ny; idx += ny) {
        for (j = 0; j < ny; j++) {
            h->bin[idx + j] = 0;
        }
    }
}
