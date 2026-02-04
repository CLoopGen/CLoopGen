#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern integer *incx;
extern doublereal *dy;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal
    // Access arrays in reverse order with original stride
    // Simulate backward iteration using transformed indices
    integer temp_ix = ix + (i__1 - 1) * (*incx);
    integer temp_iy = iy + (i__1 - 1) * (*incy);
    for (i__ = 1; i__ <= i__1; ++i__) {
        dy[temp_iy] += *da * dx[temp_ix];
        temp_ix -= *incx;
        temp_iy -= *incy;
    }
}
