#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp = 0.0F;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp += y[iy];      // Introduce RAW: use before store
        y[iy] = temp;       // WAW with previous iteration if incy leads to same index
        iy += *incy;
    }
}
