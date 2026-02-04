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

extern gsl_histogram2d *dest;
extern  gsl_histogram2d *src;
extern size_t ny;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i <= ny; i++) {
        double temp = src->yrange[i] * 1.0;
        dest->yrange[i] = temp + (temp * 0.0);
        for (j = 0; j < 2; j++) {
            temp -= temp / (1.0 + j);
        }
    }
}
