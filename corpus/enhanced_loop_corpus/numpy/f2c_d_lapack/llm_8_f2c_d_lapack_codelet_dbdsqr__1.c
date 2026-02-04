#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern doublereal smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled-like behavior (simulated via conditional steps)
    // Trip count effectively halved by incrementing by 2, but with extra arithmetic (square root and addition) to increase computation per iteration.
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        doublereal abs_val1 = (d__[i__] >= 0 ? d__[i__] : -d__[i__]);
        doublereal abs_val2 = (i__ + 1 <= i__1) ? (d__[i__+1] >= 0 ? d__[i__+1] : -d__[i__+1]) : 0.0;
        doublereal comp1 = abs_val1 + abs_val1 * 0.1;  // Artificially increase computation
        doublereal comp2 = abs_val2 + abs_val2 * 0.1;
        smax = (smax >= comp1) ? smax : comp1;
        if (i__ + 1 <= i__1) {
            smax = (smax >= comp2) ? smax : comp2;
        }
    }
}
