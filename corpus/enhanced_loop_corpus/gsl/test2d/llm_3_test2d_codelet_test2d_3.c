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
    size_t indices[240];
    for (i = 0; i <= 239; i++) {
        indices[i] = 239 - i; // reverse access pattern
    }
    for (i = 0; i <= 239; i++) {
        size_t idx = indices[i];
        h1->yrange[idx] = 900. + idx * idx;
    }
}
