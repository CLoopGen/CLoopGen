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
    // Variant 1: Strided memory access with stride of 2
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        work[i__] = 0.;
    }
    // Handle odd-sized range if needed by ensuring all elements up to i__1 are covered
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        work[i__] = 0.;
    }
}
