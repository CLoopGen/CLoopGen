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
    // Variant 1: Consecutive Memory Access (unrolled stride-2 pattern into sequential writes)
    // Instead of accessing z__[(k << 1) - 1] which is z__[2*k - 1], we reorganize the loop to write consecutive elements
    // by precomputing the source indices and writing them in order.
    integer j;
    for (j = 1; j <= i__1 - 1; ++j) {
        z__[j + 1] = z__[2 * j + 1];
    }
}
