#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *scale;
extern integer i__1;
extern integer i__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with offset indexing using pointer arithmetic
    doublereal *base = &scale[k];
    integer length = i__1 - k + 1;
    for (i__ = 0; i__ < length; ++i__) {
        *(base + i__) = 1.;
    }
}
