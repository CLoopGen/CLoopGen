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
    double *xrange = hr->xrange;
    for (i = 0; i <= 10; i++) {
        xrange[i] = 0.;
        xrange[i+1] = xrange[i] + 1.; // Introduces RAW dependency: use of xrange[i] before write to xrange[i+1]
    }
}
