#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *zx;
extern integer *incx;
extern doublecomplex *zy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer j__, offset_x, offset_y;
    offset_x = 0;
    offset_y = 0;
    for (j__ = 0; j__ < i__1; ++j__) {
        i__2 = iy + offset_y;
        i__3 = ix + offset_x;
        zy[i__2].r = zx[i__3].r;
        zy[i__2].i = zx[i__3].i;
        offset_x += *incx;
        offset_y += *incy;
    }
}
