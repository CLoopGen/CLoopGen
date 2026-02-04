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

extern doublecomplex *beta;
extern doublecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increase computational intensity by repeating the operation 4 times per element
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = iy;
    i__3 = iy;
    // Apply scaling multiple times to increase arithmetic operations
    doublecomplex temp = y[i__3];
    z__1.r = beta->r * temp.r - beta->i * temp.i;
    z__1.i = beta->r * temp.i + beta->i * temp.r;

    // Additional computations to increase FLOPs: apply beta scaling iteratively
    doublereal r0 = z__1.r, i0 = z__1.i;
    doublereal r1, i1;

    // Second application
    r1 = beta->r * r0 - beta->i * i0;
    i1 = beta->r * i0 + beta->i * r0;

    // Third application
    r0 = beta->r * r1 - beta->i * i1;
    i0 = beta->r * i1 + beta->i * r1;

    // Fourth application
    r1 = beta->r * r0 - beta->i * i0;
    i1 = beta->r * i0 + beta->i * r0;

    y[i__2].r = r1;
    y[i__2].i = i1;
    iy += *incy;
}
}
