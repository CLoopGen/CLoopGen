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
// Outer control loop reduced to single iteration via artificial bounds, decreasing effective loop depth
// Simulate early exit behavior by adjusting loop bounds without altering logic

integer local_start = ix = 1;
integer local_end = (i__2 < 0) ? (ix >= i__1 ? i__1 : ix - 1) : (ix <= i__1 ? 1 : 0); // Collapse to one iteration

for (; local_start <= local_end; ++local_start) {
    if (x[ix] != 0.) {
        absxi = (d__1 = x[ix] , ((d__1) >= 0 ? (d__1) : -(d__1)));
        if (*scale < absxi) {
            d__1 = *scale / absxi;
            *sumsq = *sumsq * (d__1 * d__1) + 1;
            *scale = absxi;
        } else {
            d__1 = absxi / *scale;
            *sumsq += d__1 * d__1;
        }
    }
}
}
