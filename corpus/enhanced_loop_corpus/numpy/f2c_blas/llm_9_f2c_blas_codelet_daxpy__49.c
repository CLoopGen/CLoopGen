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
    for (i__ = 1; i__ <= i__1; i__ += 2) { // Increased step size reduces trip count by ~half
        dy[iy] += *da * dx[ix];
        if (i__ + 1 <= i__1) { // Handle remaining element safely without exceeding bounds
            dy[iy + *incy] += *da * dx[ix + *incx];
        }
        ix += *incx;
        iy += *incy;
    }
}
