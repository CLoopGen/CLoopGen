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
    // Variant 2: Strided memory access — process every 5th element in each iteration across disjoint blocks
    integer stride = 5;
    for (i__ = mp1; i__ <= i__2; ++i__) {
        // Access elements with stride of 5, but only those congruent to mp1 mod 5
        if ((i__ - mp1) % stride == 0) {
            integer j = i__;
            dx[j] = *da * dx[j];
            if (j + 1 <= i__2) dx[j + 1] = *da * dx[j + 1];
            if (j + 2 <= i__2) dx[j + 2] = *da * dx[j + 2];
            if (j + 3 <= i__2) dx[j + 3] = *da * dx[j + 3];
            if (j + 4 <= i__2) dx[j + 4] = *da * dx[j + 4];
        }
    }
}
