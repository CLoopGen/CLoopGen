#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern real t1;
extern real t2;
extern real t3;
extern real t4;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize data access to use consecutive indexing by precomputing base offsets
    integer base_idx;
    for (j = 1; j <= i__1; ++j) {
        base_idx = j * c_dim1;
        sum = v1 * c__[base_idx + 1] + v2 * c__[base_idx + 2] + 
              v3 * c__[base_idx + 3] + v4 * c__[base_idx + 4];
        c__[base_idx + 1] -= sum * t1;
        c__[base_idx + 2] -= sum * t2;
        c__[base_idx + 3] -= sum * t3;
        c__[base_idx + 4] -= sum * t4;
    }
}
