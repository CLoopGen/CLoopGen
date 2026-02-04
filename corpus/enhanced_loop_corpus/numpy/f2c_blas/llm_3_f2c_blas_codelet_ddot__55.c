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
    // Variant 2: Strided memory access with increased stride
    // Modify access pattern to use a fixed stride of 2 (every other element)
    // This introduces a strided access pattern regardless of original incx/incy
    integer stride_x = 2;
    integer stride_y = 2;
    integer new_inc_x = (*incx > 0) ? stride_x : -stride_x;
    integer new_inc_y = (*incy > 0) ? stride_y : -stride_y;
    for (i__ = 1; i__ <= (i__1 + 1) / 2; ++i__) {
        dtemp += dx[ix] * dy[iy];
        ix += new_inc_x;
        iy += new_inc_y;
    }
}
