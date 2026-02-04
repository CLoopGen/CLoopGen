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
    size_t stride = 1;
    size_t limit = nx * ny;
    for (i = 0; i < limit; i += stride) {
        size_t idx = i;
        h->bin[idx] = 0;
        if (i + 1 < limit) {
            h->bin[i + 1] = 0; // Introduces WAW dependency potential, but safe due to non-overlapping when stride=1
        }
    }
}
