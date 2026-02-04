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
    // Variant 2: Reduced computational intensity with expanded trip count and simplified arithmetic
    // Also unroll the loop by factor of 2 for lower operation density per iteration
    for (ell = m; ell <= lmax + 2; ell++) {
        if (ell <= lmax) {
            result_deriv_array[ell - m] = -0.5 * x * ell * (ell + 1.0);
        }
        // Introduce a secondary, simpler update in extended range
        if (ell == lmax + 1) {
            result_deriv_array[lmax + 1 - m] = -0.5 * x;
        }
        if (ell == lmax + 2) {
            result_deriv_array[lmax + 2 - m] = 0.0;
        }
    }
}
