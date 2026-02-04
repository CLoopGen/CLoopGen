#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  int m;
extern  double x;
extern double *result_deriv_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ell = m; ell <= lmax; ell++) {
    const double sgn = (((ell) & 1) ? 1. : -1.);
    const double term1 = (ell - 1.) * ell;
    const double term2 = (ell + 1.) * (ell + 2.);
    const double product = term1 * term2;
    result_deriv_array[ell - m] = -0.25 * sgn * x * product;
}
}
