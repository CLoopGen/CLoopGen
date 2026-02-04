#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern integer i__2;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling restructured for forward sequential stride
    integer base;
    for (i__ = mp1; i__ <= i__2 - 4; i__ += 5) {
        base = i__;
        dx[base]     = *da * dx[base];
        dx[base + 1] = *da * dx[base + 1];
        dx[base + 2] = *da * dx[base + 2];
        dx[base + 3] = *da * dx[base + 3];
        dx[base + 4] = *da * dx[base + 4];
    }
    // Handle any remaining elements if the range isn't a multiple of 5
    for (; i__ <= i__2; ++i__) {
        dx[i__] = *da * dx[i__];
    }
}
