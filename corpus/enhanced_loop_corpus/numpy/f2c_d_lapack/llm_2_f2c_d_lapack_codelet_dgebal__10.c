#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *scale;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward direction)
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        scale[i__] = 1.;
    }
    // Handle potential odd-sized range by filling skipped indices in a second pass
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        scale[i__] = 1.;
    }
}
