#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *beta;
extern real *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing indices and using a temporary array
    // Assume y is accessed consecutively by reorganizing the access pattern with a local index
    integer base_iy = iy;
    for (i__ = 0; i__ < i__1; ++i__) {
        integer offset = i__ * abs(*incy); // Ensure positive stride for consecutive-like access
        y[base_iy + offset] = *beta * y[base_iy + offset];
    }
}
