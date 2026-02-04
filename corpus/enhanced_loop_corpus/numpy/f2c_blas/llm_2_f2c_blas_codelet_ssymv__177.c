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
    // Variant 1: Consecutive memory access by removing stride and accessing y contiguously
    // Assume incy is positive and we are zeroing consecutive elements in y starting from base index
    integer base_index = iy; // preserve starting point
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[base_index + i__ - 1] = 0.F;
    }
}
