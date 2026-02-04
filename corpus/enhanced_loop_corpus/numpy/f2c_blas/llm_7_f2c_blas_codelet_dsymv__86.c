#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *beta;
extern doublereal *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal beta_val = *beta;
    integer incy_val = *incy;
    integer temp_iy = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[temp_iy] = beta_val * y[temp_iy];
        temp_iy += incy_val;
    }
    iy = temp_iy; // Update the global iy after loop (introduces WAW dependency resolution at loop exit)
}
