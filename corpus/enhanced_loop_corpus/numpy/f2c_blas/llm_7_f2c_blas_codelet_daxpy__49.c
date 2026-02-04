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
    doublereal local_da = *da;
    doublereal *local_dy = dy;
    integer local_iy = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_dy[local_iy] = local_dy[local_iy] + local_da * dx[ix];
        ix += *incx;
        local_iy += *incy;
    }
}
