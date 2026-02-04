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
    // Variant 2: Strided memory access with stride 2, processing every second element pair in a modified range
    // Adjust loop bounds to ensure we stay within limits when accessing strided indices
    integer start = mp1;
    integer end = i__1 - 8; // Ensure we don't overflow on the last access (i__ + 8)
    for (i__ = start; i__ <= end; i__ += 10) { // Advance by 10 to maintain effective group of 5 accesses with stride 2
        stemp = stemp + 
                sx[i__]     * sy[i__]     +
                sx[i__ + 2] * sy[i__ + 2] +
                sx[i__ + 4] * sy[i__ + 4] +
                sx[i__ + 6] * sy[i__ + 6] +
                sx[i__ + 8] * sy[i__ + 8];
    }
}
