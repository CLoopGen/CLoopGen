#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *y;
extern  double h;
extern  size_t dim;
extern size_t i;
extern double * k1nu;
extern double * k2nu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_d = 0.0;
    for (i = 0; i < dim; i++) {
        const double d_i = 0.5 * (k1nu[i] + k2nu[i]) + prev_d;
        y[i] += h * d_i;
        prev_d = d_i;
    }
}
