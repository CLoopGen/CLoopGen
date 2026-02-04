#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with offset base (unroll-like consecutive pattern)
    integer start = 2;
    integer end = i__1;
    for (i__ = start; i__ <= end; ++i__) {
        coltyp[i__] = 1;
        // Ensures consecutive access pattern is preserved and explicit
    }
}
