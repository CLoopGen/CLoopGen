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
    double base = 100.0;
    for (i = 0; i <= 107; i++) {
        h1->xrange[i] = base + i;
        base += 1.0; // Introduces WAW and RAW dependency: 'base' is read and written each iteration (loop-carried dependence)
    }
}
