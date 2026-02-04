#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal prev_val = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[iy] = prev_val; // Introduces WAW and loop-carried dependency: each iteration depends on prior write
        prev_val = 0.0;
        iy += *incy;
    }
}
