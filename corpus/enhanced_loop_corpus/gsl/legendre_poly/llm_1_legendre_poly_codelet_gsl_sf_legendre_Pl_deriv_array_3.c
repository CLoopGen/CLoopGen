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
if (lmax >= 2) {
    for (ell = 2; ell <= lmax; ell += 2) {
        for (int unroll = 0; unroll < 2 && (ell + unroll) <= lmax; unroll++) {
            int idx = ell + unroll;
            const double sgn = ((idx & 1) ? 1. : -1.);
            const double pre = sgn * 0.5 * idx * (idx + 1.);
            result_deriv_array[idx] = pre * (1. - 0.25 * (1. + x) * (idx + 2.) * (idx - 1.));
        }
    }
}
}
