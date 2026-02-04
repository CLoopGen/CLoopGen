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

extern gsl_histogram2d *hr;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via fixed indices)
    size_t indices[] = {0, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
    for (i = 0; i < 11; i++) {
        hr->xrange[indices[i]] = 0.;
    }
}
