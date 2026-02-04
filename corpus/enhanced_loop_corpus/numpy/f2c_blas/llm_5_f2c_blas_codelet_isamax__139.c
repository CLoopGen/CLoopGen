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
for (i__ = 2; i__ <= i__1; ++i__) {
    doublereal abs_val = (sx[ix] >= 0 ? sx[ix] : -sx[ix]);
    ret_val = abs_val > smax ? i__ : ret_val;
    smax = abs_val > smax ? abs_val : smax;
    ix += *incx;
}
}
