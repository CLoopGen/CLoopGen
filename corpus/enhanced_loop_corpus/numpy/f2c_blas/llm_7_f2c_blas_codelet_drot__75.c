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
    doublereal local_c = *c__;
    doublereal local_s = *s;
    integer local_incx = *incx;
    integer local_incy = *incy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        dtemp = local_c * dx[ix] + local_s * dy[iy];
        dy[iy] = local_c * dy[iy] - local_s * dx[ix];
        dx[ix] = dtemp;
        ix += local_incx;
        iy += local_incy;
    }
}
