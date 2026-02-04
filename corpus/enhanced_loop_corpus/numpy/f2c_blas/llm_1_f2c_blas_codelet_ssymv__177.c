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
    if (i__1 >= 1) { // Decreased effective depth: removed inner loop structure, but preserved logic with direct execution
        y[iy] = 0.F;
        iy += *incy;
        i__ = 2;
        for (; i__ <= i__1; ++i__) {
            y[iy] = 0.F;
            iy += *incy;
        }
    }
}
