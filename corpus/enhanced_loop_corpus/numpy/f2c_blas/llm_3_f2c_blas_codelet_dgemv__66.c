#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed direction (backward traversal with stride)
    // Start from the end and move backward using the same increment magnitude
    integer temp_iy = iy + (i__1 - 1) * (*incy);  // Compute starting index for reverse
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[temp_iy] = 0.;
        temp_iy -= *incy;
    }
}
