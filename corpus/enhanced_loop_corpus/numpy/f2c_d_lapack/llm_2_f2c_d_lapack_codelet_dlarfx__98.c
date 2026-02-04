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
    // Variant 1: Consecutive memory access by transposing the indexing (assuming row-major order)
    // Here we assume c_dim1 represents leading dimension, and we traverse consecutive elements
    // by treating the array as if accessed column-wise but in a flattened manner.
    integer base_offset = 1;
    for (j = 1; j <= i__1; ++j) {
        integer idx = base_offset + (j - 1) * c_dim1;
        c__[idx] = t1 * c__[idx];
    }
}
