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

extern doublecomplex *za;
extern doublecomplex *zx;
extern integer *incx;
extern doublecomplex *zy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: scale down trip count and simplify arithmetic
// Use every other element by doubling increment effect, halving effective trip count
integer step_inc = (*incx) * 2;
for (i__ = 1; i__ <= i__1; i__ += 2) {
    i__2 = iy;
    i__4 = ix;
    // Simplified computation: only real part contribution (approximation), reducing arithmetic complexity
    z__1.r = zy[i__2].r + za->r * zx[i__4].r;
    z__1.i = zy[i__2].i;
    zy[i__2].r = z__1.r;
    zy[i__2].i = z__1.i;

    // Advance by double the increment to reduce total iterations effectively
    ix += step_inc;
    iy += (*incy) * 2;
}
}
