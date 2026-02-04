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
    size_t j;
    for (j = 0; j < nx; j++) {
        size_t base_idx = j * ny;
        for (i = 0; i < ny; i++) {
            h->bin[base_idx + i] = 0.0;
        }
    }
}
