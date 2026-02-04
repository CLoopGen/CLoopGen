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
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern integer i__;
extern integer ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer base_ix = ix - *incx; // Normalize starting point
for (i__ = 0; i__ < i__1; ++i__) {
    integer offset = i__ * (*incx); // Consecutive logical index with explicit stride
    i__2 = base_ix + offset;
    i__3 = base_ix + offset;
    z__1.r = za->r * zx[i__3].r - za->i * zx[i__3].i , z__1.i = za->r * zx[i__3].i + za->i * zx[i__3].r;
    zx[i__2].r = z__1.r , zx[i__2].i = z__1.i;
} // Sequential, predictable access pattern with fixed increments
ix = base_ix + i__1 * (*incx); // Update global ix after loop
}
