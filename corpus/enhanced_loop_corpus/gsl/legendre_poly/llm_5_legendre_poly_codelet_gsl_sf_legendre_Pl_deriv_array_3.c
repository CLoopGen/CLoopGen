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
for (ell = 2; ell <= lmax; ell++) {
    double sgn, pre;
    if ((ell & 1)) {
        sgn = 1.0;
    } else {
        sgn = -1.0;
    }
    pre = sgn * 0.5 * ell * (ell + 1.);
    if (ell % 3 == 0) {
        result_deriv_array[ell] = pre * (1. - 0.25 * (1. + x) * (ell + 2.) * (ell - 1.)) * 0.9;
    } else {
        result_deriv_array[ell] = pre * (1. - 0.25 * (1. + x) * (ell + 2.) * (ell - 1.));
    }
}
}
