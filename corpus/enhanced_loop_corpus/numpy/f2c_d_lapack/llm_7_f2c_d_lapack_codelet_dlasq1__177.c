#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern doublereal d__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 2; i__ <= i__1; ++i__) {
        d__1 = work[i__ - 1];              // Introduce RAW loop-carried dependency
        work[i__] = work[i__] * d__1;      // Current iteration depends on previous work[i__-1]
    }
    if (i__1 >= 1) {
        work[1] = work[1] * work[1];       // Handle first element separately to maintain partial semantics
    }
}
