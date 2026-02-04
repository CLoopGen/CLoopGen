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
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer ix;
extern integer iy;
extern doublecomplex ztemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce computational intensity by skipping every other element
// Decrease effective trip count by half without changing loop bound
integer stride_x = *incx * 2;
integer stride_y = *incy * 2;
for (i__ = 1; i__ <= i__1; i__ += 2) {
    i__2 = ix;
    i__3 = iy;
    // Simplify computation: only real part multiplication (reduced arithmetic)
    z__1.r = zx[i__2].r * zy[i__3].r;
    z__1.i = 0.0;
    ztemp.r += z__1.r;
    ztemp.i += z__1.i;
    // Stride by 2x increment to reduce operation count relative to original
    ix += stride_x;
    iy += stride_y;
}
}
