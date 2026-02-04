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
extern doublereal *c__;
extern doublereal *s;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        dtemp = *c__ * dx[ix] + *s * dy[iy];
        if (dtemp >= 0.0) {
            dy[iy] = *c__ * dy[iy] - *s * dx[ix];
            dx[ix] = dtemp;
        }
        ix += *incx;
        iy += *incy;
    }
}
