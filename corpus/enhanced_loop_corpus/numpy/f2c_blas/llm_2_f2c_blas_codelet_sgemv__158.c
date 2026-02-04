#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    real *y_ptr = y + iy;
    integer inc = *incy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        *y_ptr = 0.F;
        y_ptr += inc;
    }
}
