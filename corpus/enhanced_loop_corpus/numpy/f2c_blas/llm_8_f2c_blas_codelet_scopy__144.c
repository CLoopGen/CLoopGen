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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        sy[iy] = sx[ix] + sx[ix] * 0.5f;
        ix += *incx;
        iy += *incy;
    }
}
