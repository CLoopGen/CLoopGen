#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern integer *incx;
extern integer ret_val;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern integer ix;
extern doublereal dmax__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled by factor of 2)
    // Assumes incx == 1 and modifies access pattern to process two elements per iteration
    integer stride = (*incx == 1) ? 1 : *incx; // preserve original for safety
    i__ = 2;
    ix = 1; // reset base index assuming dx[0] is start, adjust if needed

    // Handle unroll factor of 2 with cleanup
    for (; i__ <= i__1 - 1; i__ += 2) {
        // First element
        if ((d__1 = dx[ix], ((d__1) >= 0 ? (d__1) : -(d__1))) > dmax__) {
            ret_val = i__;
            dmax__ = (d__1 = dx[ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
        }
        ix += stride;

        // Second element
        if ((d__1 = dx[ix], ((d__1) >= 0 ? (d__1) : -(d__1))) > dmax__) {
            ret_val = i__ + 1;
            dmax__ = (d__1 = dx[ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
        }
        ix += stride;
    }

    // Cleanup for odd-sized tail
    if (i__ <= i__1) {
        if ((d__1 = dx[ix], ((d__1) >= 0 ? (d__1) : -(d__1))) > dmax__) {
            ret_val = i__;
            dmax__ = (d__1 = dx[ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
        }
        ix += stride;
    }
}
