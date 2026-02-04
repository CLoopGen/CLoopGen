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
    // Variant 2: Reduced trip count with stride-2 loop and modified indexing
    // Lower computational load by halving iterations, using unrolled-like pattern
    integer stride = 2;
    integer bound = (i__1 % 2 == 0) ? i__1 - 1 : i__1;
    for (j = 1; j <= bound; j += stride) {
        c__[j * c_dim1 + 1] = t1 * c__[j * c_dim1 + 1];
    }
    // Handle odd-sized case if needed
    if (i__1 > bound) {
        c__[i__1 * c_dim1 + 1] = t1 * c__[i__1 * c_dim1 + 1];
    }
}
