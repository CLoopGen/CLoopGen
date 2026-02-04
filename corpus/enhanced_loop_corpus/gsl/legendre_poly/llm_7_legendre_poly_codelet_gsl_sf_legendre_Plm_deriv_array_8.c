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
        double val = -0.25 * x * (ell - 1.) * ell * (ell + 1.) * (ell + 2.);
        result_deriv_array[ell - m] = val;
        if (ell > m) {
            result_deriv_array[ell - m] += result_deriv_array[ell - m - 1];
        }
    }
}
