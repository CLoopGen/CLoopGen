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
    real *restrict local_sx = sx;
    real *restrict local_sy = sy;
    integer local_ix = ix;
    integer local_iy = iy;
    integer incx_val = *incx;
    integer incy_val = *incy;
    integer count = i__1;

    for (i__ = 1; i__ <= count; ++i__) {
        stemp = local_sx[local_ix];
        local_sx[local_ix] = local_sy[local_iy];
        local_sy[local_iy] = stemp;
        local_ix += incx_val;
        local_iy += incy_val;
    }

    // Update global indices after loop
    ix = local_ix;
    iy = local_iy;
}
