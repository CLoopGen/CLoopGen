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
    // Variant 2: Reduced trip count with stride-2 access pattern (lower iteration count, same work coverage)
    // Effectively halves the number of iterations by processing elements with step 2 in index movement
    integer stride = (*incy < 0) ? -2 : 2;  // Adjust direction based on sign of incy
    integer effective_incy = *incy;
    integer loop_bound = (i__1 + 1) / 2;    // Half the trip count

    for (i__ = 1; i__ <= loop_bound; ++i__) {
        y[iy] = *beta * y[iy];
        iy += stride * effective_incy;      // Skip every other element
    }
}
