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

extern singlecomplex *cx;
extern integer *incx;
extern singlecomplex *cy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop-carried dependence by accumulating values across iterations
    // Instead of direct assignment, we add to the previous value (RAW + WAW carried dependence)
    real sum_r = 0.0f;
    real sum_i = 0.0f;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = iy;
        i__3 = ix;
        sum_r += cx[i__3].r;
        sum_i += cx[i__3].i;
        cy[i__2].r = sum_r;
        cy[i__2].i = sum_i;
        ix += *incx;
        iy += *incy;
    }
}
