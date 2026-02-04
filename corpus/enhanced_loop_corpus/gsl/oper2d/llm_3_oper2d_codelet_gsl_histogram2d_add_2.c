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
    size_t total_size = (h1->nx) * (h1->ny);
    double *bin1 = h1->bin;
    double *bin2 = h2->bin;
    for (size_t i = 0; i < total_size; i += 2) {
        if (i + 1 < total_size) {
            bin1[i] += bin2[i];
            bin1[i + 1] += bin2[i + 1];
        } else {
            bin1[i] += bin2[i];
        }
    }
}
