#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *beta;
extern real *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled by factor of 2)
    // Assumes i__1 is even for simplicity; handles odd case with cleanup
    integer unroll_factor = 2;
    integer limit = i__1 - (i__1 % unroll_factor);
    
    for (i__ = 1; i__ <= limit; i__ += unroll_factor) {
        y[iy] = *beta * y[iy];
        iy += *incy;
        y[iy] = *beta * y[iy];
        iy += *incy;
    }
    
    // Cleanup loop for remaining iterations
    for (; i__ <= i__1; ++i__) {
        y[iy] = *beta * y[iy];
        iy += *incy;
    }
}
