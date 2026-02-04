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
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // Trip count remains the same, but each iteration performs more work
    doublereal t1_sq = t1 * t1;
    doublereal t1_inv = (t1 != 0.0) ? 1.0 / t1 : 1.0;
    for (j = 1; j <= i__1; ++j) {
        doublereal temp = c__[j * c_dim1 + 1];
        c__[j * c_dim1 + 1] = t1 * temp + t1_sq * temp * t1_inv - temp;
    }
}
