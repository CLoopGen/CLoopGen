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
extern real *c__;
extern real *s;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    real temp1 = sx[ix];
    real temp2 = sy[iy];
    stemp = *c__ * temp1 + *s * temp2;
    sy[iy] = *c__ * temp2 - *s * temp1;
    sx[ix] = stemp;
    ix += *incx;
    iy += *incy;
}
}
