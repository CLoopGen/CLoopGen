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

extern doublecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Reverse Order Traversal
    integer base_index = iy;
    integer stride = *incy;
    integer total_steps = i__1;
    
    // Compute final index to start from (reverse walk)
    integer max_offset = (total_steps - 1) * stride;
    integer current_index = base_index + max_offset;
    
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[current_index].r = 0.0;
        y[current_index].i = 0.0;
        current_index -= stride; // Move backward in strided manner
    }
    
    // Update global iy to reflect new position (points beyond last accessed element)
    iy = base_index + total_steps * stride;
}
