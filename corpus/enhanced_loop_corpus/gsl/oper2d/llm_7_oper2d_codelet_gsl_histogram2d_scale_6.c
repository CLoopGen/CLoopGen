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
extern double scale;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    double temp;
    for (i = 0; i < (h->nx) * (h->ny); i++) {
        temp = h->bin[i];
        for (j = 0; j < 1; j++) { // Artificially introduces a loop-carried dependency via dummy inner loop
            temp *= scale;
        }
        h->bin[i] = temp;
    }
}
