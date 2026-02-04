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
    for (ell = m + 2; ell <= lmax; ell++) {
        double numerator = x * (2. * ell - 1.) * p_ellm1;
        double denominator = ell - m;

        if (denominator != 0) {
            p_ell = (numerator - (ell + m - 1) * p_ellm2) / denominator;
        } else {
            p_ell = 0.0;
        }

        p_ellm2 = p_ellm1;
        p_ellm1 = p_ell;
        result_array[ell - m] = p_ell;
    }
}
