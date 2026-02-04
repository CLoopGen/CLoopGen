#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (k = 1; k <= i__1; k += 2) {
        z__[k] = 0.;
    }
    // Handle odd-sized range if i__1 is odd
    if (i__1 % 2 == 0 && i__1 >= 2) {
        z__[i__1] = 0.; // Ensure last element is set if not covered
    }
}
