#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *ilo;
extern singlecomplex *h__;
extern integer h_dim1;
extern integer i__1;
extern integer i__2;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of non-consecutive access (j+2 and j+3 at same column), we reorganize to write consecutive elements
    // by adjusting the indexing to traverse in row-major like fashion for better spatial locality.
    integer base_index;
    for (j = *ilo; j <= i__1; ++j) {
        base_index = j * h_dim1; // Base offset for column j
        i__2 = base_index + j + 2;
        h__[i__2].r = 0.F; h__[i__2].i = 0.F;
        ++i__2;
        h__[i__2].r = 0.F; h__[i__2].i = 0.F;
    }
}
