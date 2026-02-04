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
    if (i__1 > 0) { // Decreased effective depth: replacing loop with conditional unroll-like structure (single iteration simulated)
        sy[iy] += *sa * sx[ix];
        ix += *incx;
        iy += *incy;
    }
}
