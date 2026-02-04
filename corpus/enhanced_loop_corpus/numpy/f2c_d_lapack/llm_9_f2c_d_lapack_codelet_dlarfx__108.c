#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity but increased trip count via unrolling-like effect
    // Two independent operations in one loop iteration, effectively doubling work per iteration
    // without increasing arithmetic density per element.
    for (j = 1; j <= i__1 * 2; ++j) {
        if (j <= i__1) {
            c__[j + c_dim1] = t1 * c__[j + c_dim1];
        } else {
            // Secondary operation on same array with offset
            integer idx = j - i__1;
            c__[idx + c_dim1] = (t1 + 1.0) * c__[idx + c_dim1];
        }
    }
}
