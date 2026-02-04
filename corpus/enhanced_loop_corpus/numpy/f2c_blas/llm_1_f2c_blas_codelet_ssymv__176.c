#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *beta;
extern real *y;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[i__] = *beta * y[i__];
    }
} else {
    // Handle empty case with a minimal loop-like structure
    for (i__ = 1; i__ <= 0; ++i__) {
        y[i__] = *beta * y[i__];
    }
}
}
