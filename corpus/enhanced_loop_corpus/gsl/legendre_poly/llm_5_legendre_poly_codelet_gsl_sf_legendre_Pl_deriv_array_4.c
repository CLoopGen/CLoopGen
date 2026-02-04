#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_array;
extern double *result_deriv_array;
extern int ell;
extern  double diff_a;
extern  double diff_b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ell = 2; ell <= lmax; ell++) {
        double denom = diff_a * diff_b;
        if (denom < 1e-10 && denom > -1e-10) {
            result_deriv_array[ell] = 0.0;
            continue;
        }
        result_deriv_array[ell] = -ell * (x * result_array[ell] - result_array[ell - 1]) / denom;
    }
}
