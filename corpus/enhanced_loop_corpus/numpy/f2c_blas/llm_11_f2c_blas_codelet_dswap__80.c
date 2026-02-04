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
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        if (i__ + 1 <= i__1) {
            dtemp = dx[ix];
            dx[ix] = dy[iy];
            dy[iy] = dtemp;
            ix += *incx;
            iy += *incy;

            dtemp = dx[ix];
            dx[ix] = dy[iy];
            dy[iy] = dtemp;
            ix += *incx;
            iy += *incy;
        } else {
            dtemp = dx[ix];
            dx[ix] = dy[iy];
            dy[iy] = dtemp;
            ix += *incx;
            iy += *incy;
        }
    }
}
