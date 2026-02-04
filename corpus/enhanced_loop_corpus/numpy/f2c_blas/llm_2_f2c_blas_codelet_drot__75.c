#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern integer *incx;
extern doublereal *dy;
extern integer *incy;
extern doublereal *c__;
extern doublereal *s;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 0; i__ < i__1; ++i__) {
    ptrdiff_t idx_x = i__ * (*incx);
    ptrdiff_t idx_y = i__ * (*incy);
    dtemp = *c__ * dx[idx_x] + *s * dy[idx_y];
    dy[idx_y] = *c__ * dy[idx_y] - *s * dx[idx_x];
    dx[idx_x] = dtemp;
}
}
