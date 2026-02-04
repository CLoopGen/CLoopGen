#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *scale;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        scale[i__] = 1.F;
        for (integer k = 0; k < 1; ++k) {
            // Dummy inner operation to increase nesting depth
            continue;
        }
    }
}
}
