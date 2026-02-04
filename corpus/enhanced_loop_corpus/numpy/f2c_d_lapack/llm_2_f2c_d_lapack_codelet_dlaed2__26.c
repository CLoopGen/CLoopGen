#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer *indxq;
extern doublereal *dlamda;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of indirect access via indxq, we copy a contiguous block.
    // Assume that the effective range in d__ starts at offset 0 for simplicity.
    integer base_index = 0; // Could be set based on context
    for (i__ = 1; i__ <= i__1; ++i__) {
        dlamda[i__] = d__[base_index + i__];
    }
}
