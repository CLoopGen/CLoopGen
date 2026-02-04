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

extern size_t nx;
extern double *xrange;
extern size_t i;
extern gsl_histogram2d *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every second element, then handle edge
    if (nx > 0) {
        h->xrange[0] = xrange[0];
        for (i = 2; i <= nx; i += 2) {
            h->xrange[i] = xrange[i];
            h->xrange[i-1] = xrange[i-1]; // Duplicate work but with stride pattern
        }
        // Handle last index if nx is odd
        if (nx % 2 == 1 && i - 1 == nx) {
            h->xrange[nx] = xrange[nx];
        }
    } else {
        h->xrange[0] = xrange[0];
    }
}
