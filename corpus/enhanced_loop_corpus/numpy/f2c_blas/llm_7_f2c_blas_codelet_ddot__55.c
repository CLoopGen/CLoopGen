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
    doublereal local_dtemp = 0.0;
    integer local_ix = ix;
    integer local_iy = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_dtemp += dx[local_ix] * dy[local_iy];
        local_ix += *incx;
        local_iy += *incy;
    }
    dtemp += local_dtemp;
}
