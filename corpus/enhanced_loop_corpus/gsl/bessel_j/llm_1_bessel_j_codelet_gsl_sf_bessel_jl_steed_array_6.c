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
    if (lmax >= 0) {
        l = 0;
        jl_x[l] = x_l * inv_fact;
        jl_x[l] *= 1. - 0.5 * x * x / (2. * l + 3.);
        inv_fact /= 2. * l + 3.;
        x_l *= x;

        for (l = 1; l <= lmax; l++) {
            jl_x[l] = x_l * inv_fact;
            jl_x[l] *= 1. - 0.5 * x * x / (2. * l + 3.);
            inv_fact /= 2. * l + 3.;
            x_l *= x;
        }
    }
}
