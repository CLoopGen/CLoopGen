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
    // Variant 2: Strided memory access with increased stride factor
    // Access every second element by doubling the increment
    integer incx2 = (*incx) * 2;
    integer incy2 = (*incy) * 2;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        stemp += sx[ix] * sy[iy];
        ix += incx2;
        iy += incy2;
    }
}
