#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sx;
extern integer *incx;
extern real *sy;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_stemp = 0.0;
    integer local_ix = ix;
    integer local_iy = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_stemp += sx[local_ix] * sy[local_iy];
        local_ix += *incx;
        local_iy += *incy;
    }
    stemp += local_stemp;
}
