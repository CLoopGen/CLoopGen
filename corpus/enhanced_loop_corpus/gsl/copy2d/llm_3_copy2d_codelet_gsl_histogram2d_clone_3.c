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

extern  gsl_histogram2d *src;
extern size_t nx;
extern size_t ny;
extern size_t i;
extern gsl_histogram2d *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse array from end to beginning)
    size_t total = nx * ny;
    for (size_t i = total; i > 0; ) {
        i--;
        h->bin[i] = src->bin[i];
    }
}
