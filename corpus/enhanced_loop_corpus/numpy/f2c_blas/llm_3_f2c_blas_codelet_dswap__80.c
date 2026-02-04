#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern integer *incx;
extern doublereal *dy;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_iterations = i__1;
    for (int outer = 0; outer < total_iterations; ++outer) {
        i__ = outer + 1;
        dtemp = dx[ix];
        dx[ix] = dy[iy];
        dy[iy] = dtemp;
        ix += *incx;
        iy += *incy;
    }
}
