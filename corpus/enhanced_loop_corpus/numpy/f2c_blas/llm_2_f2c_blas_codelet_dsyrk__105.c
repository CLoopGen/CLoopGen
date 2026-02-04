#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the loop order
    // Instead of column-major inner loop, we iterate over a temporary linear index
    // to promote spatial locality in row-wise (consecutive) access.
    integer idx;
    i__2 = *n;
    for (j = 1; j <= i__1; ++j) {
        for (idx = j + j * c_dim1; idx <= i__2 + j * c_dim1; idx += c_dim1) {
            c__[idx] = 0.;
        }
    }
}
