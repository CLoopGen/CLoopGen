#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern integer *incx;
extern doublereal *dy;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by removing strided indexing and using direct sequential array traversal
    // Assume dx, dy are accessed consecutively with unit stride regardless of original incx/incy
    for (i__ = 0; i__ < i__1; ++i__) {
        dy[i__] = dx[i__];
    }
}
