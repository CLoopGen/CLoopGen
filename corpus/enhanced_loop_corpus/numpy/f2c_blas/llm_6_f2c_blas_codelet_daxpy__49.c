#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern integer *incx;
extern doublereal *dy;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp += *da * dx[ix];
        ix += *incx;
        iy += *incy;
    }
    dy[iy - *incy * (i__1)] += temp;
}
