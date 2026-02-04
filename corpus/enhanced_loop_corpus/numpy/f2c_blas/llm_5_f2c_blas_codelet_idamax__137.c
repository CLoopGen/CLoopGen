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
for (i__ = 2; i__ <= i__1; ++i__) {
    doublereal abs_val = (dx[ix] >= 0) ? dx[ix] : -dx[ix];
    ret_val = (abs_val > dmax__) ? i__ : ret_val;
    dmax__ = (abs_val > dmax__) ? abs_val : dmax__;
    ix += *incx;
}
}
