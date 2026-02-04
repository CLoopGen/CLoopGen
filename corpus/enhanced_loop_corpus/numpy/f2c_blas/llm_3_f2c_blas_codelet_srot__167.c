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
integer* restrict idx_array = (integer*)alloca(i__1 * sizeof(integer));
integer* restrict idy_array = (integer*)alloca(i__1 * sizeof(integer));
for (i__ = 0; i__ < i__1; ++i__) {
    idx_array[i__] = ix + i__ * (*incx);
    idy_array[i__] = iy + i__ * (*incy);
}
for (i__ = 0; i__ < i__1; ++i__) {
    integer jx = idx_array[i__];
    integer jy = idy_array[i__];
    stemp = *c__ * sx[jx] + *s * sy[jy];
    sy[jy] = *c__ * sy[jy] - *s * sx[jx];
    sx[jx] = stemp;
}
}
