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
for (i__ = 0; i__ < i__1; ++i__) {
    integer index_x = ix + i__ * (*incx);
    integer index_y = iy + i__ * (*incy);
    stemp = *c__ * sx[index_x] + *s * sy[index_y];
    sy[index_y] = *c__ * sy[index_y] - *s * sx[index_x];
    sx[index_x] = stemp;
}
}
