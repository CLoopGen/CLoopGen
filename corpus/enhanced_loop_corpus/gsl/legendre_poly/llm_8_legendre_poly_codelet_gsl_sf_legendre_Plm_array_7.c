#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  int m;
extern  double x;
extern double *result_array;
extern double p_ellm2;
extern double p_ellm1;
extern double p_ell;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled computation pattern
    // Trip count remains the same, but each iteration performs more work via expanded recurrence expression
    double temp1, temp2;
    for (ell = m + 2; ell <= lmax; ell += 2) {
        // First iteration step (unrolled by 2)
        temp1 = (x * (2.0 * ell - 1.0) * p_ellm1 - (ell + m - 1) * p_ellm2) / (ell - m);
        p_ellm2 = p_ellm1;
        p_ellm1 = temp1;
        result_array[ell - m] = temp1;

        // Second iteration step, if within bounds
        if (ell + 1 <= lmax) {
            temp2 = (x * (2.0 * (ell + 1) - 1.0) * p_ellm1 - (ell + 1 + m - 1) * p_ellm2) / ((ell + 1) - m);
            p_ellm2 = p_ellm1;
            p_ellm1 = temp2;
            result_array[ell + 1 - m] = temp2;
        }
    }
}
