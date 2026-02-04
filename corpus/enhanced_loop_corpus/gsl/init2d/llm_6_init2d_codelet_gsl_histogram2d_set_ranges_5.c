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
        j = i + 1;
        if (j <= nx) {
            h->xrange[i] = xrange[j]; // RAW dependency: xrange[j] used before h->xrange[i] is written
        } else {
            h->xrange[i] = xrange[i];
        }
    }
}
