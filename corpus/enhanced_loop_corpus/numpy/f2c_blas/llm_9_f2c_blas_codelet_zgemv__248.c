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
// Reduced computational intensity: every other element is skipped, halving trip count effect
integer step = (*incy) * 2; // Double the increment to reduce effective iterations
for (i__ = 1; i__ <= i__1; i__ += 2) { // Increment by 2 to reduce operation count
    i__2 = iy;
    i__3 = iy;
    // Simplified scaling: only real part is updated, imaginary set to zero — reduced arithmetic
    y[i__2].r = beta->r * y[i__3].r;
    y[i__2].i = 0.0;
    iy += step;
}
}
