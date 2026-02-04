#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp = 0.0F;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp += tau[i__];      // Introduce loop-carried dependency via 'temp'
        tau[i__] = 0.F;
    }
    // Additional use of temp to prevent dead code elimination
    if (i__1 > 0) tau[1] = temp * 0.F;
}
