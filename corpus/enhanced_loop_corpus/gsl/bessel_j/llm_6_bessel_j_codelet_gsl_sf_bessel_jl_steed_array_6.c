#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *jl_x;
extern double inv_fact;
extern double x_l;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_inv_fact = inv_fact;
    double temp_x_l = x_l;
    for (l = 0; l <= lmax; l++) {
        jl_x[l] = temp_x_l * temp_inv_fact;
        jl_x[l] *= 1. - 0.5 * x * x / (2. * l + 3.);
        temp_inv_fact /= 2. * l + 3.;
        temp_x_l *= x;
    }
}
