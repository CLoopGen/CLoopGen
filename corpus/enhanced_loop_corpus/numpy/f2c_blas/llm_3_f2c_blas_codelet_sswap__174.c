#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sx;
extern real *sy;
extern integer i__1;
extern integer i__;
extern integer mp1;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (access every 4th element instead of consecutive triplets)
    // Simulates a strided pattern by skipping elements, still using step of 3 in index but with stride in data layout
    const integer stride = 4;
    integer start = mp1;
    i__ = start;
    for (; i__ <= i__1; i__ += 3 * stride) {
        stemp = sx[i__];
        sx[i__] = sy[i__];
        sy[i__] = stemp;
        if (i__ + stride <= i__1) {
            stemp = sx[i__ + stride];
            sx[i__ + stride] = sy[i__ + stride];
            sy[i__ + stride] = stemp;
        }
        if (i__ + 2 * stride <= i__1) {
            stemp = sx[i__ + 2 * stride];
            sx[i__ + 2 * stride] = sy[i__ + 2 * stride];
            sy[i__ + 2 * stride] = stemp;
        }
    }
}
