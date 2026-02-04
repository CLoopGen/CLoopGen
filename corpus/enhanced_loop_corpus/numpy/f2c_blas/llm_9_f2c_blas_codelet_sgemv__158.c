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
    for (i__ = 1; i__ <= i__1 * 2; ++i__) {
        y[iy] = 0.F;
        if (i__ % 2 == 0) {
            iy += *incy;
        }
    }
}
