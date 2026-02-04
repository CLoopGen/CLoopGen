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
    real local_accum = 0.0F;
    integer temp_iy = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_accum += y[temp_iy];
        temp_iy += *incy;
    }
    // Eliminate loop-carried dependency by deferring write
    temp_iy = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[temp_iy] = local_accum; // All writes depend on final accumulated value
        temp_iy += *incy;
    }
}
