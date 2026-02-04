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
    // Variant 2: Strided access with reversed traversal order (backward striding)
    // Traverse from the last element to the first using negative stride logic
    integer current_iy = iy + (i__1 - 1) * (*incy);
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[current_iy] = *beta * y[current_iy];
        current_iy -= *incy;
    }
}
