#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *y;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward order)
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        y[i__] = 0.;
    }
    // Handle potential odd-sized range by processing remaining element
    if (i__ - 1 < i__1) {
        y[i__ - 1 + 1] = 0.;
    }
}
