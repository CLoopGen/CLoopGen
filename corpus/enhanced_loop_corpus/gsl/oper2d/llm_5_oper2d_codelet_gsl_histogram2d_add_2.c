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
extern  gsl_histogram2d *h2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t n = (h1->nx) * (h1->ny);
    for (i = 0; i < n; i++) {
        if (i % 2 == 0 || i % 2 == 1) {
            h1->bin[i] += h2->bin[i];
        }
    }
}
