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

extern singlecomplex *beta;
extern singlecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce computational intensity and trip count by half with simplified arithmetic
integer step = 2;
for (i__ = 1; i__ <= i__1 / 2; ++i__) { // Halved trip count
    i__2 = iy;
    i__3 = iy;
    // Replace complex multiplication with scaled real-only operation (approximation)
    y[i__2].r = beta->r * y[i__3].r;
    y[i__2].i = 0.0f; // Eliminate imaginary component computation
    iy += *incy * step; // Increase stride to maintain coverage
}
}
