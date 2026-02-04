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
    imax = 0;
    jmax = 0;
    for (i = 0; i < nx; i++) {
        double row_max = -__builtin_huge_val();
        size_t row_jmax = 0;
        for (j = 0; j < ny; j++) {
            double x = h->bin[i * ny + j];
            if (x > row_max) {
                row_max = x;
                row_jmax = j;
            }
        }
        if (row_max > max) {
            max = row_max;
            imax = i;
            jmax = row_jmax;
        }
    }
}
