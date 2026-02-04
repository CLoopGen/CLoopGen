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
    // Variant 2: Reduced computational intensity with halved effective trip count using step increment
    if (i__1 > 0) {
        for (i__ = 1; i__ <= i__1; i__ += 2) {  // Effectively half the iterations
            stemp = sx[ix];
            sx[ix] = sy[iy];
            sy[iy] = stemp;
            ix += *incx * 2;  // Adjust index step to maintain consistency
            iy += *incy * 2;
        }
    }
}
