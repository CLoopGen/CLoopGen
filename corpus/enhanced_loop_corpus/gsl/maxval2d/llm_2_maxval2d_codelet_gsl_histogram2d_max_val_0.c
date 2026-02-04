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

extern  gsl_histogram2d *h;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern
    // Instead of accessing h->bin sequentially, we traverse with a stride of 2,
    // then handle the remaining elements in a second pass if needed.
    size_t stride = 2;
    size_t total = nx * ny;

    // First pass: odd indices
    for (i = 1; i < total; i += stride) {
        if (h->bin[i] > max) {
            max = h->bin[i];
        }
    }

    // Second pass: even indices
    for (i = 0; i < total; i += stride) {
        if (h->bin[i] > max) {
            max = h->bin[i];
        }
    }
}
