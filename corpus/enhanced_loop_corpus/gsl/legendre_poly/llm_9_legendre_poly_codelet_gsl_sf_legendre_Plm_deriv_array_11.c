#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  int m;
extern  double x;
extern double *result_array;
extern double *result_deriv_array;
extern int ell;
extern  double diff_a;
extern  double diff_b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double inv_diff = 1.0 / (diff_a * diff_b);
    for (ell = m + 2; ell <= lmax; ell++) {
        double term1 = ell * x * result_array[ell - m];
        double term2 = (ell + m) * result_array[ell - 1 - m];
        result_deriv_array[ell - m] = -(term1 - term2) * inv_diff;
    }
}
