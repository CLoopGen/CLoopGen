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
    // Variant 2: Strided Memory Access with Fixed Stride (stride of 2 elements)
    // Simulates processing every second element first, then the others
    // This modifies access pattern to improve cache locality in some scenarios
    integer base_offset;
    integer step = 2;
    
    // Process even-indexed logical iterations (original odd indices due to 1-based)
    base_offset = iy;
    for (i__ = 1; i__ <= i__1; i__ += step) {
        y[base_offset] = *beta * y[base_offset];
        base_offset += *incy * step;
    }
    
    // Process odd-indexed logical iterations (original even indices)
    base_offset = iy + *incy;
    for (i__ = 2; i__ <= i__1; i__ += step) {
        y[base_offset] = *beta * y[base_offset];
        base_offset += *incy * step;
    }
}
