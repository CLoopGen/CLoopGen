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
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublecomplex accumulator = {0.0, 0.0}; // Accumulate over iterations (introduce WAW and loop-carried dependency)
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = i__;
    // Use accumulated value instead of direct beta scaling — creates loop-carried dependency
    z__1.r = accumulator.r * y[i__2].r - accumulator.i * y[i__2].i;
    z__1.i = accumulator.r * y[i__2].i + accumulator.i * y[i__2].r;

    // Update accumulator with current y value scaled by beta (creates WAW and RAW)
    accumulator.r += beta->r * y[i__2].r;
    accumulator.i += beta->i * y[i__2].i;

    y[i__2].r = z__1.r;
    y[i__2].i = z__1.i;
}
}
