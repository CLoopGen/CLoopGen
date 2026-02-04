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
    doublereal local_beta = *beta;
    integer stride = *incy;
    integer index = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[index] *= local_beta;
        index += stride;
    }
    iy = index;
}
