#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *work;
extern integer i__1;
extern real r__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1 - 1; ++i__) {
        r__1 = work[i__ + 1];               // Shift access: read next element early
        work[i__] = work[i__] * work[i__];  // Independent squaring (original operation)
        work[i__ + 1] = r__1 * r__1;        // Write to next in advance — introduces RAW and WAW loop-carried dependencies
    }
    // Handle last element if i__1 >= 1
    if (i__1 >= 1) {
        work[i__1] = work[i__1] * work[i__1];
    }
}
