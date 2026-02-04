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
    double *yrange = hr->yrange;
    for (i = 0; i <= 5; i++) {
        yrange[i] = 0.;
        yrange[i+1] = yrange[i] + 1.0; // Introduces RAW dependency: current iteration reads result of previous
    }
}
