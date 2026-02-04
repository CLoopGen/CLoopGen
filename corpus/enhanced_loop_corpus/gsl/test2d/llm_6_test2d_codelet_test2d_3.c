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
    double base = 900.0;
    double prev_val = base;
    for (i = 0; i <= 239; i++) {
        double curr_val = (i == 0) ? base : prev_val + (i * i - (i-1) * (i-1));
        h1->yrange[i] = curr_val;
        prev_val = curr_val;
    }
}
