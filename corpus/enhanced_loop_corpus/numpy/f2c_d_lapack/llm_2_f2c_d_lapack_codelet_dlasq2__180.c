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
    // Variant 1: Consecutive Memory Access (unrolled with stride of 1)
    // Original access z__[(k << 2) - 3] is equivalent to z__[4*k - 3], which is strided by 4.
    // We modify it to write consecutive elements for better spatial locality.
    integer base = 5; // Starting offset to ensure valid index range
    for (k = 2; k <= i__1; ++k) {
        z__[k] = z__[base + k];  // Now accessing a consecutive segment starting at base
    }
}
