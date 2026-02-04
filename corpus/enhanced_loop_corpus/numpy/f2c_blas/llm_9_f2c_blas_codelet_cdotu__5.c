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

extern singlecomplex *cx;
extern integer *incx;
extern singlecomplex *cy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer ix;
extern integer iy;
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce computational intensity by decreasing arithmetic operations and trip count
// Simulate lower workload: process every second element and skip complex multiply-add
integer step = 2;
for (i__ = 1; i__ <= i__1; i__ += step) {
    i__2 = ix;
    i__3 = iy;
    // Replace full complex multiplication with a simplified real-part-only approximation
    q__2.r = cx[i__2].r * cy[i__3].r;
    q__2.i = 0.0f;
    ctemp.r += q__2.r;
    // Skip imaginary accumulation entirely
    ix += (*incx) * step;
    iy += (*incy) * step;
}
}
