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
    for (size_t j = 0; j < h1->nx; j++) {
        for (size_t k = 0; k < h1->ny; k++) {
            size_t i = j * h1->ny + k;
            h1->bin[i] -= h2->bin[i];
        }
    }
}
