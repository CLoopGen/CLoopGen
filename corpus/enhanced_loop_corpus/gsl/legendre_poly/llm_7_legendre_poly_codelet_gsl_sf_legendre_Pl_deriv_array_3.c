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
double prev_result = 0.0;
for (ell = 2; ell <= lmax; ell++) {
    const double sgn = (((ell) & 1) ? 1. : -1.);
    const double pre = sgn * 0.5 * ell * (ell + 1.);
    const double val = pre * (1. - 0.25 * (1. + x) * (ell + 2.) * (ell - 1.));
    result_deriv_array[ell] = val + 0.1 * prev_result;
    prev_result = val;
}
}
