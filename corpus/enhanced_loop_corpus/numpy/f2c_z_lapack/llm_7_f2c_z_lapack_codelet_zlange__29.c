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
    for (i__ = 1; i__ <= i__1; ++i__) {
        work[i__] = work[i__ - 1];
    }
    // Replaces constant assignment with a loop-carried RAW dependency
    // Each iteration depends on the previous iteration's value via work[i__ - 1]
    // Assumes work[0] is defined and i__1 >= 1; transforms independent stores into a data-flow chain
    // Eliminates original WAW independence by creating sequential read-after-write pattern
}
