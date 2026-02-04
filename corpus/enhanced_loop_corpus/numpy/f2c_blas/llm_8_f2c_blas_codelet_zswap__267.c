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
extern doublecomplex ztemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    if (i__ + 1 <= i__1) {
        i__2 = ix;
        ztemp.r = zx[i__2].r , ztemp.i = zx[i__2].i;
        i__2 = ix;
        i__3 = iy;
        zx[i__2].r = zy[i__3].r , zx[i__2].i = zy[i__3].i;
        i__2 = iy;
        zy[i__2].r = ztemp.r , zy[i__2].i = ztemp.i;
        ix += *incx;
        iy += *incy;

        i__2 = ix;
        ztemp.r = zx[i__2].r , ztemp.i = zx[i__2].i;
        i__2 = ix;
        i__3 = iy;
        zx[i__2].r = zy[i__3].r , zx[i__2].i = zy[i__3].i;
        i__2 = iy;
        zy[i__2].r = ztemp.r , zy[i__2].i = ztemp.i;
        ix += *incx;
        iy += *incy;
    } else {
        i__2 = ix;
        ztemp.r = zx[i__2].r , ztemp.i = zx[i__2].i;
        i__2 = ix;
        i__3 = iy;
        zx[i__2].r = zy[i__3].r , zx[i__2].i = zy[i__3].i;
        i__2 = iy;
        zy[i__2].r = ztemp.r , zy[i__2].i = ztemp.i;
        ix += *incx;
        iy += *incy;
    }
}
}
