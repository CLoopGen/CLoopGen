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
    if ((d__1 = dx[ix] , ((d__1) >= 0 ? (d__1) : -(d__1))) <= dmax__) {
        goto L5;
    }
    ret_val = i__;
    dmax__ = (d__1 = dx[ix] , ((d__1) >= 0 ? (d__1) : -(d__1)));
  L5:
    ix += *incx;
}

}
