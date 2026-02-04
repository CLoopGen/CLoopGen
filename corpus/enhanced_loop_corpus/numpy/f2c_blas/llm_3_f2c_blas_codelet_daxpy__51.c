#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern doublereal *dy;
extern integer i__1;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (access every 8th element, unrolled by 4)
    integer stride = 8;
    integer start = mp1;
    integer end = i__1 - 3 * stride; // Ensure we don't go out of bounds
    for (i__ = start; i__ <= end; i__ += stride) {
        dy[i__] += *da * dx[i__];
        dy[i__ + stride] += *da * dx[i__ + stride];
        dy[i__ + 2*stride] += *da * dx[i__ + 2*stride];
        dy[i__ + 3*stride] += *da * dx[i__ + 3*stride];
    }
}
