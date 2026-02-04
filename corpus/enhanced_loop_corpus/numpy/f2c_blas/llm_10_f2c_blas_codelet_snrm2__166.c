#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *x;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer ix;
extern real ssq;
extern real scale;
extern real absxi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified branching and increased trip count via finer steps
    integer fine_step = i__2 / 2;
    if (fine_step == 0) fine_step = i__2;  // Prevent zero step
    integer fine_bound = i__1 * 2;  // Double the trip count approximately

    for (ix = 1; i__2 < 0 ? ix >= fine_bound : ix <= fine_bound; ix += fine_step) {
        // Use a temporary index mapped to original array spacing
        integer mapped_ix = 1 + (ix - 1) / 2;

        if (x[mapped_ix] == 0.F) continue;

        // Simplified absolute value using bit manipulation alternative (still using ternary for portability)
        absxi = (r__1 = x[mapped_ix], (r__1) >= 0 ? r__1 : -r__1);

        // Merge comparison and update with fused operation to reduce branches
        doublereal ratio = (scale < absxi) ? (scale / absxi) : (absxi / scale);
        doublereal ratio_sq = (real)(ratio * ratio);

        if (scale < absxi) {
            ssq = ssq * ratio_sq + 1.F;
            scale = absxi;
        } else {
            ssq += ratio_sq;
        }
    }
}
