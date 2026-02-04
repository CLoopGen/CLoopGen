#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *ca;
extern singlecomplex *cx;
extern integer *incx;
extern singlecomplex *cy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce computational intensity by decreasing arithmetic operations and increasing step size
// Also reduce effective trip count by stepping through every 2nd element

integer step = 2;
for (i__ = 1; i__ <= i__1; i__ += step) {
    i__2 = iy;
    i__4 = ix;
    // Simplify: only perform real part update, skip imaginary component (reduction in ops)
    cy[i__2].r = cy[i__2].r + ca->r * cx[i__4].r;
    // Skip complex arithmetic entirely for this variant

    // Update pointers with stride
    ix += *incx * step;
    iy += *incy * step;
}
}
