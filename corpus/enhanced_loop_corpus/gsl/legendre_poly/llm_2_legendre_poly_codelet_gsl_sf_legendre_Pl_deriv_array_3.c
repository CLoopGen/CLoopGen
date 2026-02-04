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
    // Variant 1: Strided memory access with reverse traversal
    for (ell = lmax; ell >= 2; ell -= 2) {
        const double sgn = (((ell) & 1) ? 1. : -1.);
        const double pre = sgn * 0.5 * ell * (ell + 1.);
        result_deriv_array[ell] = pre * (1. - 0.25 * (1. + x) * (ell + 2.) * (ell - 1.));
    }
    // Handle remaining index if lmax is odd
    if ((lmax & 1) && (lmax >= 2)) {
        ell = lmax - 1;
        if (ell >= 2) {
            const double sgn = (((ell) & 1) ? 1. : -1.);
            const double pre = sgn * 0.5 * ell * (ell + 1.);
            result_deriv_array[ell] = pre * (1. - 0.25 * (1. + x) * (ell + 2.) * (ell - 1.));
        }
    }
}
