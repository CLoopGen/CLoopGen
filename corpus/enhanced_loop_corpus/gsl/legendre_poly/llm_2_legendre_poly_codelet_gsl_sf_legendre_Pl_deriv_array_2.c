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
    // Variant 1: Strided memory access with step size of 2 (writing to even indices only)
    // This changes the memory access pattern from consecutive to strided
    for (ell = 2; ell <= lmax; ell += 2) {
        const double pre = 0.5 * ell * (ell + 1.);
        result_deriv_array[ell] = pre * (1. - 0.25 * (1. - x) * (ell + 2.) * (ell - 1.));
    }
    // Fill remaining odd indices above 2 if needed, in a second pass (to maintain correctness)
    for (ell = 3; ell <= lmax; ell += 2) {
        const double pre = 0.5 * ell * (ell + 1.);
        result_deriv_array[ell] = pre * (1. - 0.25 * (1. - x) * (ell + 2.) * (ell - 1.));
    }
}
