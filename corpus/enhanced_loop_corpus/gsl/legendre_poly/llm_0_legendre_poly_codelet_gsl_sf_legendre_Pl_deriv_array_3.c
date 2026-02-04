#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_deriv_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 1; outer++) {
    for (ell = 2; ell <= lmax; ell++) {
        const double sgn = (((ell) & 1) ? 1. : -1.);
        const double pre = sgn * 0.5 * ell * (ell + 1.);
        result_deriv_array[ell] = pre * (1. - 0.25 * (1. + x) * (ell + 2.) * (ell - 1.));
    }
}
}
