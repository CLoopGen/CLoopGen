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
extern double scale;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = h->nx * h->ny;
    for (i = 0; i < limit; i++) {
        // Introduce control dependency: skip zero-valued bins to avoid redundant operations
        if (h->bin[i] == 0.0) {
            continue;
        }
        h->bin[i] *= scale;
    }
}
