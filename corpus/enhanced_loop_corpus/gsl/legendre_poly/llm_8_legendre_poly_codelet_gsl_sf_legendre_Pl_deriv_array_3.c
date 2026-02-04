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
for (ell = 2; ell <= lmax; ell += 2) {
    const double sgn = (((ell) & 1) ? 1. : -1.);
    const double pre = sgn * 0.5 * ell * (ell + 1.);
    result_deriv_array[ell] = pre * (1. - 0.25 * (1. + x) * (ell + 2.) * (ell - 1.));
    if (ell + 1 <= lmax) {
        const double sgn_next = ((((ell + 1)) & 1) ? 1. : -1.);
        const double pre_next = sgn_next * 0.5 * (ell + 1) * (ell + 2);
        result_deriv_array[ell + 1] = pre_next * (1. - 0.25 * (1. + x) * (ell + 3) * ell);
    }
}
}
