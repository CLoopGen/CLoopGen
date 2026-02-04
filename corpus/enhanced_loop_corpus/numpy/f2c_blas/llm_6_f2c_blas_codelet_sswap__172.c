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
    real temp1, temp2;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp1 = sx[ix];
        temp2 = sy[iy];
        sx[ix] = temp2;
        sy[iy] = temp1;
        ix += *incx;
        iy += *incy;
    }
}
