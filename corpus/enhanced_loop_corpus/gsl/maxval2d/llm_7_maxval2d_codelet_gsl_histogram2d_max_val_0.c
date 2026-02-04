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
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_max = -__builtin_huge_val();
    for (i = 0; i < nx * ny; i += 2) {
        double val1 = h->bin[i];
        double val2 = (i + 1 < nx * ny) ? h->bin[i + 1] : val1;
        double local_max = (val1 > val2) ? val1 : val2;
        if (local_max > temp_max) {
            temp_max = local_max;
        }
    }
    max = temp_max;
}
