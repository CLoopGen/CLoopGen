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
    size_t step = 2;
    for (i = 0; i <= 106; i += step) {
        if (h1->xrange[i] != h->xrange[i] || h1->xrange[i+1] != h->xrange[i+1])
            status = 1;
    }
    // Handle last element if range is odd-sized
    if (i == 106 && h1->xrange[107] != h->xrange[107])
        status = 1;
}
