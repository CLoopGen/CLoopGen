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
    double inv_diff = 1.0 / (diff_a * diff_b);
    for (ell = 2; ell <= lmax; ell++) {
        double term1 = x * result_array[ell];
        double term2 = result_array[ell - 1];
        double diff_term = term1 - term2;
        result_deriv_array[ell] = -ell * diff_term * inv_diff;
    }
}
