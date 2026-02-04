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
    // Handle odd-sized ranges by including the next index if needed
    if (i__ - 1 < i__1) {
        work[i__ - 1 + 1] = 0.;
    }
}
