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
    if (i__1 <= 0) {
        return;
    }
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (sx[ix] != 0.0f && sy[iy] != 0.0f) {
            stemp += sx[ix] * sy[iy];
        }
        ix += *incx;
        iy += *incy;
    }
}
