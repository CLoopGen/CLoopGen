#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *scale;
extern integer i__1;
extern integer i__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with offset indexing using pointer arithmetic
    real *base = &scale[k];
    integer len = i__1 - k + 1;
    for (i__ = 0; i__ < len; ++i__) {
        *(base + i__) = 1.F;
    }
}
