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

extern gsl_histogram2d *dest;
extern  gsl_histogram2d *src;
extern size_t nx;
extern size_t ny;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    size_t i;
    size_t total = nx * ny;

    for (i = total; i > 0; i--) {
        dest->bin[i - 1] = src->bin[i - 1];
    }
}
