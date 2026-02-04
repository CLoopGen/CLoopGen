#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *y;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[i__] = 0.F;
        y[i__ - 1] = 0.F;  // Introduce WAW and WAR dependencies: overlapping writes to adjacent indices
    }
    if (i__1 >= 1) {
        y[0] = 0.F;  // Fix potential underflow from last iteration
    }
}
