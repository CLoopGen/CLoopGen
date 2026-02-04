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
    // Variant 2: Strided memory access by processing every second element
    // First pass: handle even indices in the logical range, then odd if needed
    // Here we simulate a strided access pattern with step size 2
    int start = m;
    // Adjust start to ensure stride-2 covers all elements
    for (ell = start; ell <= lmax; ell += 2) {
        const double sgn = (((ell) & 1) ? 1. : -1.);
        result_deriv_array[ell - m] = -0.25 * sgn * x * (ell - 1.) * ell * (ell + 1.) * (ell + 2.);
    }
    // Second pass: handle remaining elements with offset if m allows
    int start2 = m + 1;
    if (start2 <= lmax) {
        for (ell = start2; ell <= lmax; ell += 2) {
            const double sgn = (((ell) & 1) ? 1. : -1.);
            result_deriv_array[ell - m] = -0.25 * sgn * x * (ell - 1.) * ell * (ell + 1.) * (ell + 2.);
        }
    }
}
