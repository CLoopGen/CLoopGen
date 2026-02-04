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
    real temp_sy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        stemp = *c__ * sx[ix] + *s * sy[iy];
        temp_sy = *c__ * sy[iy] - *s * sx[ix];
        sx[ix] = stemp;
        sy[iy] = temp_sy;
        ix += *incx;
        iy += *incy;
    }
}
