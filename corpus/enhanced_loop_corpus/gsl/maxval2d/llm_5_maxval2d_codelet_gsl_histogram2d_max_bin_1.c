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
extern size_t imax;
extern size_t jmax;
extern size_t i;
extern size_t j;
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max = -__builtin_huge_val();
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            double x = h->bin[i * ny + j];
            if (!(x > max)) continue;
            max = x;
            imax = i;
            jmax = j;
        }
    }
}
