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
    // Variant 1: Consecutive memory access by precomputing indices and accessing y in increasing order
    integer base_index = 1;
    for (i__ = 0; i__ < i__1; ++i__) {
        integer idx = base_index + i__;
        y[idx].r = 0.F;
        y[idx].i = 0.F;
    }
    // Update global iy after the loop to maintain semantic consistency
    iy = 1 + i__1 * (*incy);
}
