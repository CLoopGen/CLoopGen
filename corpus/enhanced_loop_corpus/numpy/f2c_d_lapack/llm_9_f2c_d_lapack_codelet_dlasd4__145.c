#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *d__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal temp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and simplified operations
    integer trip_count = (i__1 < *n) ? i__1 * 2 : i__1;
    for (j = 1; j <= trip_count; ++j) {
        integer idx = (j % i__1 == 0) ? i__1 : j % i__1; // Wrap-around indexing
        work[idx] += d__[idx];            // Accumulate instead of assign, simpler operation
        delta[idx] = d__[idx] - temp1;    // Remove redundant term (d[*n]) to reduce ops
    }
}
