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
    const double inv_ell = 1.0 / ell;
    const double sgn = (((ell) & 1) ? 1. : -1.);
    const double temp1 = ell + 1.;
    const double temp2 = ell + 2.;
    const double temp3 = ell - 1.;
    const double pre = sgn * 0.5 * ell * temp1;
    const double factor = 1. - 0.25 * (1. + x) * temp2 * temp3;
    result_deriv_array[ell] = pre * factor * inv_ell;
}
}
