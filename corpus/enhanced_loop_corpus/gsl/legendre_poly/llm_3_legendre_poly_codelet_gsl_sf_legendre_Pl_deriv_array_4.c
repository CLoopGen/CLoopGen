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
    // Variant 2: Consecutive access with temporary array-like behavior using offset pointers
    // Introduce pointer arithmetic to create consecutive access pattern
    // This variant uses base-shifted pointers to simulate more regular memory flow
    double *res_deriv = result_deriv_array + 2;
    double *res_val = result_array + 2;
    double *res_val_prev = result_array + 1; // points to [ell-1] when res_val is [ell]

    int local_ell;
    for (local_ell = 2; local_ell <= lmax; local_ell++) {
        res_deriv[local_ell - 2] = -local_ell * (x * res_val[local_ell - 2] - res_val_prev[local_ell - 2]) / (diff_a * diff_b);
    }
}
