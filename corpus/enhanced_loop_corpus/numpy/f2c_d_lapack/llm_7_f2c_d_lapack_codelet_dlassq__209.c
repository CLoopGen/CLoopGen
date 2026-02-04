#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *x;
extern doublereal *scale;
extern doublereal *sumsq;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer ix;
extern doublereal absxi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_scale = *scale;
    doublereal local_sumsq = *sumsq;
    integer step = i__2;
    integer bound = i__1;
    for (ix = 1; step < 0 ? ix >= bound : ix <= bound; ix += step) {
        if (x[ix] != 0.) {
            absxi = (d__1 = x[ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
            if (local_scale < absxi) {
                d__1 = local_scale / absxi;
                local_sumsq = local_sumsq * (d__1 * d__1) + 1;
                local_scale = absxi;
                *sumsq = local_sumsq; // WAW: Early write to shared state
                *scale = local_scale;
            } else {
                d__1 = absxi / local_scale;
                local_sumsq += d__1 * d__1;
                *sumsq = local_sumsq; // RAW: Use of updated sumsq in next iteration possible
            }
        }
    }
    *sumsq = local_sumsq;
    *scale = local_scale;
}
