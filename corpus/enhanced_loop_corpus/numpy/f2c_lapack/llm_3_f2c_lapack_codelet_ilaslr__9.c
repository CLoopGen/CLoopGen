#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer ret_val;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Modify memory access to use consecutive access pattern by transposing iteration order
// and accessing elements in row-major-like fashion assuming column-major storage
for (j = 1; j <= i__1; ++j) {
    // Iterate upwards to promote cache-friendly access if a is stored row-wise
    for (i__ = 1; i__ <= *m; ++i__) { // Reverse loop direction: bottom-up traversal
        // Convert to linear consecutive access via index remapping
        integer idx = j + i__ * a_dim1; // Swapped indexing to simulate different stride behavior
        if (a[idx] != 0.F) {
            goto L10;
        }
    }
  L10:
    ret_val = ((ret_val) >= (i__) ? (ret_val) : (i__));
}
}
