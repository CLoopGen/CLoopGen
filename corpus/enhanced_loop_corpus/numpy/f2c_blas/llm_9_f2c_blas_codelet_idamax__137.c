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
    integer stride = *incx * 2;
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        doublereal abs_current = (d__1 = dx[ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
        doublereal abs_next = 0.0;
        integer ix_next = ix + *incx;
        
        if (i__ + 1 <= i__1) {
            abs_next = (d__1 = dx[ix_next], ((d__1) >= 0 ? (d__1) : -(d__1)));
        }

        if (abs_current > dmax__) {
            ret_val = i__;
            dmax__ = abs_current;
        }
        if (i__ + 1 <= i__1 && abs_next > dmax__) {
            ret_val = i__ + 1;
            dmax__ = abs_next;
        }
        
        ix += stride;
    }
    // Handle odd-sized tail if needed via adjusted trip count logic
    if ((i__1 - 1) % 2 == 0 && i__ <= i__1 + 1) {
        doublereal abs_val = (d__1 = dx[ix - *incx], ((d__1) >= 0 ? (d__1) : -(d__1)));
        if (abs_val > dmax__) {
            ret_val = i__1;
            dmax__ = abs_val;
        }
    }
}
