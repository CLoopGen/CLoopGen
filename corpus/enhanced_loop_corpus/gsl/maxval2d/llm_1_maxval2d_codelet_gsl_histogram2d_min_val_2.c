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
    if (nx == 0 || ny == 0) return;
    size_t i = 0;
    for (size_t j = 0; j < nx * ny; j += 16) {
        for (size_t k = j; k < j + 16 && k < nx * ny; k++) {
            if (h->bin[k] < min) {
                min = h->bin[k];
            }
        }
    }
}
