#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sa;
extern real *sx;
extern integer *incx;
extern real *sy;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled by factor of 2)
    // Assumption: i__1 is even; if not, remainder handled by original logic
    integer unroll_factor = 2;
    integer limit = i__1 - (i__1 % unroll_factor);
    
    for (i__ = 1; i__ <= limit; i__ += unroll_factor) {
        sy[iy] += *sa * sx[ix];
        ix += *incx;
        iy += *incy;
        
        sy[iy] += *sa * sx[ix];
        ix += *incx;
        iy += *incy;
    }
    
    // Handle remaining iterations
    for (; i__ <= i__1; ++i__) {
        sy[iy] += *sa * sx[ix];
        ix += *incx;
        iy += *incy;
    }
}
