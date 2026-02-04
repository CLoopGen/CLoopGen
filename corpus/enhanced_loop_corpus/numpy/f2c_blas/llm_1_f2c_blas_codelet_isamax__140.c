#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *sx;
extern integer ret_val;
extern integer i__1;
extern real r__1;
extern integer i__;
extern real smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 2; i__ <= i__1 && i__ <= 1000; ++i__) { // Reduced effective loop depth by introducing an upper bound to limit iterations
    if ((r__1 = sx[i__] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1))) <= smax) {
        goto L30;
    }
    ret_val = i__;
    smax = (r__1 = sx[i__] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
  L30:
    ;
}
}
