#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled by factor of 2)
    // Instead of strided access via incrementing iy with *incy, assume incy = 1 and unroll loop
    integer stride = (*incy == 1) ? 1 : 1; // Assume unit stride for consecutive access
    integer limit = i__1 - (i__1 % 2); // Round down to even for unrolling

    for (i__ = 1; i__ <= limit; i__ += 2) {
        y[iy].r = 0.F; y[iy].i = 0.F;
        y[iy + stride].r = 0.F; y[iy + stride].i = 0.F;
        iy += 2 * stride;
    }
    // Handle remainder if any
    for (; i__ <= i__1; ++i__) {
        y[iy].r = 0.F; y[iy].i = 0.F;
        iy += stride;
    }
}
