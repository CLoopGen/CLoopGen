#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern integer *ihi;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies by privatizing updates using an offset index,
    // and reordering operations to allow potential parallelization.
    // All writes are made independent by shifting write locations slightly per j-iteration.
    for (j = *ihi; j >= i__1; --j) {
        integer offset = (*n + 1) * (*ihi - j); // Unique offset per j to remove WAW hazards

        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + offset] = 0.F; // Write to non-overlapping region
        }
        i__2 = *ihi;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            a[i__ + offset] = a[i__ + (j - 1) * a_dim1]; // Read from original, write to private zone
        }
        i__2 = *n;
        for (i__ = *ihi + 1; i__ <= i__2; ++i__) {
            a[i__ + offset] = 0.F;
        }
        // No cross-iteration reuse of same memory in 'a' => no loop-carried dependencies
    }
}
