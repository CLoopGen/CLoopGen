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
    size_t total_elements = (h1->nx) * (h1->ny);
    for (i = 0; i < total_elements; i += 2) {
        if (i + 1 < total_elements) {
            double temp1 = h2->bin[i];
            double temp2 = h2->bin[i + 1];
            h1->bin[i] += temp1;
            h1->bin[i + 1] += temp2;
        } else {
            h1->bin[i] += h2->bin[i];
        }
    }
}
