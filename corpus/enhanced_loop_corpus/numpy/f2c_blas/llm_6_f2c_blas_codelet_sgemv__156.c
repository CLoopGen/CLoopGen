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
    real temp = 0.F;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = y[i__] + temp;  // Introduce RAW dependency: temp depends on previous iteration
        y[i__] = 0.F;
    }
}
