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
    size_t total = nx * ny;
    for (i = 0; i < total; i += 4) {
        h->bin[i] = 0;
        if (i + 1 < total) h->bin[i + 1] = 0;
        if (i + 2 < total) h->bin[i + 2] = 0;
        if (i + 3 < total) h->bin[i + 3] = 0;
    }
}
