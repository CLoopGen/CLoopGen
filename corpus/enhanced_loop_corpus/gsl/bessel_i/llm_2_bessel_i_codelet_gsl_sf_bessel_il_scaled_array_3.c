#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_array;
extern int ell;
extern double iellp1;
extern double iell;
extern double iellm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the iteration order and adjusting array indexing
    // The computation is preserved, but result_array is filled in forward order using a calculated index.
    int idx = 0;
    for (ell = 1; ell <= lmax; ell++) {
        iellm1 = iellp1 + (2 * (lmax - ell + 1) + 1) / x * iell;
        iellp1 = iell;
        iell = iellm1;
        result_array[idx++] = iellm1;
    }
}
