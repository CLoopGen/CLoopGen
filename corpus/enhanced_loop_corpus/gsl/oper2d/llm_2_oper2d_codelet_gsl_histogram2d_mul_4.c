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



void loop() {
    size_t nx = h1->nx;
    size_t ny = h1->ny;
    double *bin1 = h1->bin;
    double *bin2 = h2->bin;
    for (i = 0; i < nx * ny; i += 2) {
        bin1[i] *= bin2[i];
        if (i + 1 < nx * ny) {
            bin1[i + 1] *= bin2[i + 1];
        }
    }
}
