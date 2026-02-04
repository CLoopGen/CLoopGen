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
const integer stride = 4;
for (i__ = 0; i__ < i__1; i__ += stride) {
    integer offset;
    for (offset = 0; offset < stride && (i__ + offset) < i__1; ++offset) {
        stemp = sx[ix + (i__ + offset) * (*incx)];
        sx[ix + (i__ + offset) * (*incx)] = sy[iy + (i__ + offset) * (*incy)];
        sy[iy + (i__ + offset) * (*incy)] = stemp;
    }
}
}
