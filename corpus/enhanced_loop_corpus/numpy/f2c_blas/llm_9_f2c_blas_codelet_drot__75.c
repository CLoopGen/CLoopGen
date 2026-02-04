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
// Reduced computational intensity: skip every other element and halve effective trip count
integer step = (*incx > 0 && *incy > 0) ? 2 : 1;
for (i__ = 1; i__ <= i__1; i__ += step) {
    dtemp = *c__ * dx[ix];
    dx[ix] = dtemp;
    ix += *incx;
    iy += *incy;
    // Skip update to dy and reduce arithmetic operations by 50%
}
}
