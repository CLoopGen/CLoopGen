#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern integer *incx;
extern doublereal *dy;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_dx, temp_dy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_dx = dx[ix];
        temp_dy = dy[iy];
        dx[ix] = temp_dy;
        dy[iy] = temp_dx;
        ix += *incx;
        iy += *incy;
    }
}
