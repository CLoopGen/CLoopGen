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
    // and reduced trip count by half to maintain balance.
    integer j_step = 2;
    for (j = 1; j <= i__1; j += j_step) {
        doublereal val = c__[j + c_dim1];
        c__[j + c_dim1] = t1 * val + t1 - val * 0.5; // Increased arithmetic complexity
    }
}
