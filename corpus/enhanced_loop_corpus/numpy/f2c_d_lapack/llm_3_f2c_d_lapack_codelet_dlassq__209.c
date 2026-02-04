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
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    integer offset = 5;  // Simulate indirect access by accessing ix+offset
    for (ix = 1; i__2 < 0 ? ix >= i__1 : ix <= i__1; ix += i__2) {
        integer mapped_ix = (ix + offset) % (i__1 + 1);  // Create indirect-like access pattern
        if (mapped_ix == 0) mapped_ix = 1;  // Avoid zero index if needed
        if (x[mapped_ix] != 0.) {
            absxi = (d__1 = x[mapped_ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
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
