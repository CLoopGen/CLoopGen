#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern real t1;
extern real t2;
extern real t3;
extern real t4;
extern real t5;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with fewer operations and modified trip count for lower workload
    integer j;
    // Reduce effective trip count to half (or nearest odd if needed)
    integer limit = (i__1 + 1) / 2;
    for (j = 1; j <= limit; ++j) {
        // Simplify computation: use only three terms instead of five
        sum = v1 * c__[j + c_dim1] + v3 * c__[j + c_dim1 * 3] + v5 * c__[j + c_dim1 * 5];
        // Apply updates to only two arrays instead of five
        c__[j + c_dim1] -= sum * t1;
        c__[j + c_dim1 * 3] -= sum * t3;
    }
}
