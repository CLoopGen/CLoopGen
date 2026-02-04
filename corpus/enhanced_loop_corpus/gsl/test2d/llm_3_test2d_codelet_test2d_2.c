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

extern gsl_histogram2d *h1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    size_t indices[108];
    for (size_t j = 0; j <= 107; j++) {
        indices[j] = j; // Populate index map (could be randomized or reordered in real use)
    }
    for (i = 0; i <= 107; i++) {
        h1->xrange[indices[i]] = 100. + indices[i];
    }
}
