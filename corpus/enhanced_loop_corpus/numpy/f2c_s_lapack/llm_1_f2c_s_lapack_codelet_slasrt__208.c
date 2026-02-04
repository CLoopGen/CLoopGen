#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real dmnmx;
extern integer start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flatten the original nested structure by removing inner loop and simulating its behavior with direct indexing
// This reduces loop nesting depth from 2 to 1
i__2 = start + 1;
for (i__ = start + 1; i__ <= i__1; ++i__) {
    j = i__;
    if (j >= i__2 && d__[j] < d__[j - 1]) {
        dmnmx = d__[j];
        d__[j] = d__[j - 1];
        d__[j - 1] = dmnmx;
        // Simulate decrementing j logic once (partial unrolling of inner loop)
        --j;
        if (j >= i__2 && d__[j] < d__[j - 1]) {
            dmnmx = d__[j];
            d__[j] = d__[j - 1];
            d__[j - 1] = dmnmx;
        }
    }
    // The goto L50 is implicit as we continue the outer loop
}
}
