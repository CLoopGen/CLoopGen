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
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    for (i = 0; i <= 239; i += stride) {
        h1->yrange[i] = 900. + i * i;
        if (i + 1 <= 239) {
            h1->yrange[i + 1] = 900. + (i + 1) * (i + 1);
        }
    }
}
