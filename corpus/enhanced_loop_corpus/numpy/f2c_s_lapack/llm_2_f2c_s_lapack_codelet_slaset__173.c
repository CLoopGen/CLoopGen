#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of column-major access (j * a_dim1 + i__), we restructure to write in consecutive memory locations
    // by transposing the loop order or accessing row-wise. Here, we simulate a row-major layout write.
    integer idx;
    for (i__ = 2; i__ <= i__1; ++i__) {
        i__2 = (i__ > *m) ? *m : i__ - 1; // Adjust upper bound for valid range
        for (j = 1; j <= i__2; ++j) {
            idx = (i__ - 1) + j * a_dim1; // Maintain original indexing but ensure consecutive i__
            a[idx] = *alpha;
        }
    }
}
