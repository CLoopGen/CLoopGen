#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern doublereal *dy;
extern integer i__1;
extern integer i__;
extern integer mp1;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — access every 2nd element in a grouped pattern
    // Simulate strided traversal by increasing step meaningfully and adjusting bounds
    // We maintain accumulation over groups of 5, but now with stride of 2 between active elements
    // Note: Assumes adjusted problem size and alignment; modifies access pattern to simulate stride-2
    integer stride = 2;
    integer limit = i__1 - 4 * stride;
    for (i__ = mp1; i__ <= limit; i__ += 5 * stride) {
        dtemp = dtemp + 
            dx[i__] * dy[i__] +
            dx[i__ + stride] * dy[i__ + stride] +
            dx[i__ + 2*stride] * dy[i__ + 2*stride] +
            dx[i__ + 3*stride] * dy[i__ + 3*stride] +
            dx[i__ + 4*stride] * dy[i__ + 4*stride];
    }
}
