#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *ilo;
extern doublereal *h__;
extern integer h_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations
    // Instead of accessing two separate non-consecutive elements per iteration,
    // we process them in a pattern that improves spatial locality if multiple iterations are unrolled or vectorized.
    integer j_start = *ilo;
    integer j_end = i__1;

    for (j = j_start; j <= j_end; ++j) {
        integer base_index = j + j * h_dim1;
        h__[base_index + 2] = 0.;
        h__[base_index + 3] = 0.;
    }
}
