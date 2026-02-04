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
    double temp[240];
    for (i = 0; i <= 239; i++) {
        temp[i] = 900. + i * i;
    }
    for (i = 0; i <= 239; i++) {
        h1->yrange[i] = temp[i];
    }
}
