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

extern gsl_histogram2d *h1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 216; i++) {
        double index_val = (double)(i / 2);
        h1->xrange[i / 2] = 100. + index_val;
    }
}
