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
    for (i = 0; i <= 107; i += 3) {
        h1->xrange[i] = 100. + i;
        if (i + 1 <= 107) h1->xrange[i + 1] = 100. + (i + 1);
        if (i + 2 <= 107) h1->xrange[i + 2] = 100. + (i + 2);
    }
}
