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

extern size_t ny;
extern double *yrange;
extern size_t j;
extern gsl_histogram2d *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    for (j = 0; j <= ny; j += stride) {
        if (j <= ny) h->yrange[j] = yrange[j];
    }
    // Handle the last element if ny is odd and not hit by stride
    if ((ny % 2 == 1) && (ny > 0) && (ny % stride != 0)) {
        h->yrange[ny] = yrange[ny];
    }
}
