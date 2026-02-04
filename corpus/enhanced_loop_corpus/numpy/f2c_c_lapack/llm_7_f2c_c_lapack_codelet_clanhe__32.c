#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *work;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        work[i__] = work[i__] * 2.F;  // Introduce WAW and WAR hazard potential via reuse of same location
        work[i__] = 0.F;              // Overwrite with zero — creates intra-iteration write-after-write
    }
}
