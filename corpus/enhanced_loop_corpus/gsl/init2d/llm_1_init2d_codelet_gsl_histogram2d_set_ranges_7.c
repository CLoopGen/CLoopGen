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



void loop(){
    size_t limit = nx * ny;
    for (size_t stride = 16, i = 0; i + stride <= limit; i += stride) {
        h->bin[i + 0] = 0;
        h->bin[i + 1] = 0;
        h->bin[i + 2] = 0;
        h->bin[i + 3] = 0;
        h->bin[i + 4] = 0;
        h->bin[i + 5] = 0;
        h->bin[i + 6] = 0;
        h->bin[i + 7] = 0;
        h->bin[i + 8] = 0;
        h->bin[i + 9] = 0;
        h->bin[i + 10] = 0;
        h->bin[i + 11] = 0;
        h->bin[i + 12] = 0;
        h->bin[i + 13] = 0;
        h->bin[i + 14] = 0;
        h->bin[i + 15] = 0;
    }
    for (; i < limit; i++) {
        h->bin[i] = 0;
    }
}
