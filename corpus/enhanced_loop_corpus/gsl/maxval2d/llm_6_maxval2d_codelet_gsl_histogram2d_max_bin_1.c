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
    double local_max = max;
    size_t local_imax = imax;
    size_t local_jmax = jmax;
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            size_t idx = i * ny + j;
            double x = h->bin[idx];
            if (x > local_max) {
                local_max = x;
                local_imax = i;
                local_jmax = j;
            }
        }
    }
    max = local_max;
    imax = local_imax;
    jmax = local_jmax;
}
