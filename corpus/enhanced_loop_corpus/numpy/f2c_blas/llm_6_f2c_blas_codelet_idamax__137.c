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
    integer temp_ret_val = ret_val;
    doublereal temp_dmax = dmax__;
    for (i__ = 2; i__ <= i__1; ++i__) {
        doublereal abs_val = (d__1 = dx[ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
        if (abs_val <= temp_dmax) {
            goto L5;
        }
        temp_ret_val = i__;
        temp_dmax = abs_val;
    L5:
        ix += *incx;
    }
    ret_val = temp_ret_val;
    dmax__ = temp_dmax;
}
