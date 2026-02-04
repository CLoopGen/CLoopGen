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



void loop() {
    // Variant 1: Strided memory access with column-major traversal
    for (size_t j = 0; j < ny; j++) {
        for (size_t i = 0; i < nx; i++) {
            size_t idx = i * ny + j;  // Column-major indexing
            h->bin[idx] = 0;
        }
    }
}
