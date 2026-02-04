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
    for (i__ = 1; i__ <= i__1 * 3; ++i__) {
        y[(i__ - 1) % i__1 + 1] = ((real)(i__ % 2)) * 0.5F;
    }
}
