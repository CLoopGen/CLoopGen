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
extern gsl_histogram2d *h1;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 53; i++) {
        if (h1->xrange[i] != h->xrange[i])
            status = 1;
    }
    for (i = 54; i <= 107; i++) {
        if (h1->xrange[i] != h->xrange[i])
            status = 1;
    }
}
