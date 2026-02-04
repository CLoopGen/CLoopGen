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
    // Variant 2: Consecutive reverse-order memory access
    // We precompute the starting index and traverse forward, but map to a reversed segment in result_array
    // This simulates writing into a buffer that will be read in reverse, or aligns with stack-like usage
    int base_index = lmax - m;  // Maximum offset we need
    for (ell = m + 2; ell <= lmax; ell++) {
        p_ell = (x * (2. * ell - 1.) * p_ellm1 - (ell + m - 1) * p_ellm2) / (ell - m);
        p_ellm2 = p_ellm1;
        p_ellm1 = p_ell;
        result_array[base_index - (ell - m)] = p_ell;  // Reverse consecutive access
    }
}
