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
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = iy;
    i__3 = iy;
    // Unroll the loop by factor of 2 to increase computational intensity
    if (i__ + 0 <= i__1) {
        q__1.r = beta->r * y[i__3].r - beta->i * y[i__3].i;
        q__1.i = beta->r * y[i__3].i + beta->i * y[i__3].r;
        y[i__2].r = q__1.r;
        y[i__2].i = q__1.i;
        integer temp_iy = iy + *incy;
        if (temp_iy < i__1 * (*incy)) { // Prevent out-of-bounds
            i__2 = temp_iy;
            i__3 = temp_iy;
            q__1.r = beta->r * y[i__3].r - beta->i * y[i__3].i;
            q__1.i = beta->r * y[i__3].i + beta->i * y[i__3].r;
            y[i__2].r = q__1.r;
            y[i__2].i = q__1.i;
        }
        i__++; // Increment extra due to unrolling
    }
    iy += *incy;
}
}
