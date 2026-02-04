#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_array;
extern double p_ellm2;
extern double p_ellm1;
extern double p_ell;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write using temporary array-like indexing via pointer arithmetic
    // Simulates a shifted base pointer and consecutive storage
    // Introduces a local pointer to create a new access pattern
    double *base_result = result_array - 2;  // Shift base so that base_result[ell] maps to result_array[ell-2]
    for (ell = 2; ell <= lmax; ell++) {
        p_ell = (x * (2 * ell - 1) * p_ellm1 - (ell - 1) * p_ellm2) / ell;
        p_ellm2 = p_ellm1;
        p_ellm1 = p_ell;
        base_result[ell] = p_ell;  // Now accessing as consecutive offset from shifted base
    }
}
