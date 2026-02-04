#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__1;
extern integer i__;
extern doublereal b1;
extern doublereal d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_b1 = b1;
    for (i__ = 1; i__ <= i__1; ++i__) {
        d1 += local_b1;
        local_b1 *= 2.0; // Introduce WAW and WAR dependency on local_b1, eliminate loop-carried RAW on b1
    }
}
