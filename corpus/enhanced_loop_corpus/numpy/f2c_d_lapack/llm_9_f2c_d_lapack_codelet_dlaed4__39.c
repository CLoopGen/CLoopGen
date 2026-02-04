#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i__;
extern doublereal *d__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal tau;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via artificial split
    // Each original index is processed in two steps, increasing iterations but simplifying operations
    integer temp_i1 = i__1 * 2;
    for (j = 1; j <= temp_i1; ++j) {
        integer idx = (j + 1) / 2;  // Map expanded index back to original
        if (j % 2 == 1) {
            // First pass: initialize with partial computation
            delta[idx] = d__[idx] - d__[*i__];
        } else {
            // Second pass: finalize with subtraction of tau
            delta[idx] = delta[idx] - tau;
        }
    }
}
