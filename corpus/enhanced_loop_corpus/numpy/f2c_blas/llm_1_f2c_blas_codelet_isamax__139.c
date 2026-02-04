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
if (i__1 >= 2) {
    i__ = 2;
    do {
        if ((r__1 = sx[ix] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1))) <= smax) {
            goto L5;
        }
        ret_val = i__;
        smax = (r__1 = sx[ix] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
      L5:
        ix += *incx;
        ++i__;
    } while (i__ <= i__1);
}
}
