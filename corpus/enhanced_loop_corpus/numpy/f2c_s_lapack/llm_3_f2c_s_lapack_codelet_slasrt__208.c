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



void loop() {
    // Variant 2: Consecutive Forward Access with Unrolled Comparison
    // Change inner loop to forward consecutive access and unroll comparison logic
    // Simulates a more cache-friendly access pattern by scanning forward
    for (i__ = start + 1; i__ <= i__1 - 1; ++i__) {
        i__2 = i__ + 1;
        for (j = i__; j < i__2 && j + 1 <= i__1; ++j) {  // Forward traversal with bounds check
            if (d__[j + 1] < d__[j]) {
                dmnmx = d__[j + 1];
                d__[j + 1] = d__[j];
                d__[j] = dmnmx;
            } else {
                goto L50;
            }
        }
      L50:
        ;
    }
}
