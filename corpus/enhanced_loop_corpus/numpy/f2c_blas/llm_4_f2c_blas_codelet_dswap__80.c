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
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (assuming incx and incy are 1)
    // We simplify the indexing to direct sequential access by removing strided index updates
    integer base_x = ix - 1; // Adjust base so dx[base_x + i__] corresponds to original dx[ix]
    integer base_y = iy - 1;
    for (i__ = 0; i__ < i__1; ++i__) {
        dtemp = dx[base_x + i__];
        dx[base_x + i__] = dy[base_y + i__];
        dy[base_y + i__] = dtemp;
    }
}
