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
    r__1 = sx[ix];
    doublereal abs_val = (r__1 >= 0 ? r__1 : -r__1);
    if (abs_val > smax) {
        ret_val = i__;
        smax = abs_val;
    }
    ix += *incx;
}
}
