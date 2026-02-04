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
    size_t stride = 2;
    for (i = 0; i <= 10; i += stride) {
        if (i / stride <= 5) {
            hr->yrange[i / stride] = 0.;
        }
    }
}
