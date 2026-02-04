#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *zx;
extern integer *incx;
extern doublecomplex *zy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by half and increase work per iteration
    integer step = 2;
    integer limit = i__1 / 2;
    for (i__ = 1; i__ <= limit; ++i__) {
        i__2 = iy;
        i__3 = ix;
        // Copy two elements per iteration (unrolled behavior)
        zy[i__2].r = zx[i__3].r; zy[i__2].i = zx[i__3].i;
        
        // Second operation if within bounds
        integer ix2 = ix + *incx;
        integer iy2 = iy + *incy;
        if (ix2 > 0 && iy2 > 0 && i__ * 2 + 1 <= i__1) { // Safe access check
            i__2 = iy2;
            i__3 = ix2;
            zy[i__2].r = zx[i__3].r; zy[i__2].i = zx[i__3].i;
        }
        ix += *incx * step;
        iy += *incy * step;
    }
}
