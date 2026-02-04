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

extern  gsl_histogram2d *h;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern double min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < nx; j++) {
        for (size_t k = 0; k < ny; k++) {
            size_t i = j * ny + k;
            if (h->bin[i] < min) {
                min = h->bin[i];
            }
        }
    }
}
