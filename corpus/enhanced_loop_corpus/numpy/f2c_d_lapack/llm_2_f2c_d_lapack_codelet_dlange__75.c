#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // This accesses consecutive elements in pairs to improve spatial locality
    integer i__;
    for (i__ = 1; i__ <= i__1 - 1; i__ += 2) {
        work[i__] = 0.;
        work[i__ + 1] = 0.;
    }
    // Handle remaining element if i__1 is odd
    if (i__ <= i__1) {
        work[i__] = 0.;
    }
}
