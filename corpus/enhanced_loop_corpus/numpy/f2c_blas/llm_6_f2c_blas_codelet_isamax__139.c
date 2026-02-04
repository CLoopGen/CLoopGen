#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *sx;
extern integer *incx;
extern integer ret_val;
extern integer i__1;
extern real r__1;
extern integer i__;
extern integer ix;
extern real smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_ret_val = ret_val;
    real temp_smax = smax;
    for (i__ = 2; i__ <= i__1; ++i__) {
        real abs_val = (r__1 = sx[ix], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        if (abs_val <= temp_smax) {
            goto L5;
        }
        temp_ret_val = i__;
        temp_smax = abs_val;
    L5:
        ix += *incx;
    }
    ret_val = temp_ret_val;
    smax = temp_smax;
}
