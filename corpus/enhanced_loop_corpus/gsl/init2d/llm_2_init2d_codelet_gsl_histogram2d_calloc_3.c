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
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the array with a stride equal to the size of nx,
    // wrapping around when exceeding bounds. This creates a non-consecutive access pattern.
    size_t total = nx * ny;
    size_t stride = (nx > 1) ? nx : 2; // Ensure stride is meaningful
    size_t start;
    for (start = 0; start < stride; start++) {
        size_t j;
        for (j = start; j < total; j += stride) {
            h->bin[j] = 0;
        }
    }
}
