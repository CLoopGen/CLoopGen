#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *beta;
extern real *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = y[iy];
        y[iy] = *beta * temp;
        iy += *incy;
    }
}
