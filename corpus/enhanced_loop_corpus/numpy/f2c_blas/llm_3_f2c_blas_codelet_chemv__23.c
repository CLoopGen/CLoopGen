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
    // Variant 2: Strided access with reversed iteration and stride applied directly in indexing
    integer step = *incy > 0 ? -(*incy) : (*incy); // Ensure correct direction
    integer current_iy = iy + (i__1 - 1) * (*incy);
    for (i__ = i__1; i__ >= 1; --i__) {
        y[current_iy].r = 0.F;
        y[current_iy].i = 0.F;
        current_iy -= *incy;
    }
    // Final update of global iy to reflect last value
    iy = current_iy;
}
