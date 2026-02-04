#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
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
    // Variant 1: Consecutive memory access pattern
    // Assume incx and incy are both 1 (consecutive access)
    // We'll remove strided indexing and use direct sequential access
    integer base_x = ix - 1; // adjust to start from 0-based offset
    integer base_y = iy - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
        dy[base_y + i__] += *da * dx[base_x + i__];
    }
}
