#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *work;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        work[i__] = 0.F;
    }
} else {
    // Handle empty iteration space with a single dummy iteration
    i__ = 1;
    work[i__] = 0.F;
}
}
