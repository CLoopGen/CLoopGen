#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *beta;
extern doublereal *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled by factor of 2)
    // Assume i__1 is even for simplicity; handles pairs of elements per iteration
    integer i__;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        y[iy] = *beta * y[iy];
        iy += *incy;
        if (i__ + 1 <= i__1) {
            y[iy] = *beta * y[iy];
            iy += *incy;
        }
    }
}
