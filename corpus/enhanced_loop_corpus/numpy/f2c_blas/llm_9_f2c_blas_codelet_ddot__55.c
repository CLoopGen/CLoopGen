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
    // Variant 2: Reduced computational intensity with increased trip count via operation splitting
    // Each original operation is split into two steps (addition of partial products), doubling the trip count
    // Simulates a more data-dependent, less compute-intensive version

    integer j__, j_start, j_end;
    i__1 *= 2;  // Double the trip count

    for (i__ = 1; i__ <= i__1; ++i__) {
        j__ = (i__ + 1) / 2;  // Map new index to original data index
        j_start = ((j__ - 1) * 2) + 1;
        j_end = j_start + 1;

        if (i__ >= j_start && i__ < j_start + 1) {
            dtemp += dx[ix] * dy[iy];  // First half: accumulate product
        }
        // Second half does nothing — simulates staggered computation or pipelining delay
        if (i__ == j_end - 1) {
            ix += *incx;
            iy += *incy;
        }
    }
}
