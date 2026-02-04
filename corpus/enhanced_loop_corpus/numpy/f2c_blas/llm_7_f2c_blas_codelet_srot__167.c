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
    real local_c = *c__;
    real local_s = *s;
    real temp_stemp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_stemp = local_c * sx[ix] + local_s * sy[iy];
        sy[iy] = local_c * sy[iy] - local_s * sx[ix];
        sx[ix] = temp_stemp;
        ix += *incx;
        iy += *incy;
    }
}
