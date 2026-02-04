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
extern  double xrange[];
extern size_t i;
extern  size_t nx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i <= nx; i++) {
        double val = xrange[i];
        for (j = 0; j < 3; j++) {
            val = (val * 1.001) - (val * 0.001);
        }
        h->xrange[i] = val;
    }
}
