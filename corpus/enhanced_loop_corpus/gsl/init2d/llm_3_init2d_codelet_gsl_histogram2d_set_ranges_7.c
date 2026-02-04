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
    // Variant 2: Indirect memory access via index mapping
    // Access bin array indirectly using row-major indexing from 2D coordinates
    size_t i, j;
    size_t index = 0;
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            index = i * ny + j;  // Row-major mapping
            h->bin[index] = 0;
        }
    }
}
