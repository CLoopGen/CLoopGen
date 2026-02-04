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
    for (size_t j = 0; j < 2; j++) {
        for (i = 0; i <= nx; i++) {
            h->xrange[i] = xrange[i];
        }
    }
}
