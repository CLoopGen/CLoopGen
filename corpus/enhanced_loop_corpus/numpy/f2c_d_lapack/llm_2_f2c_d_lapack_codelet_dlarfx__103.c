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
extern doublereal t2;
extern doublereal t3;
extern doublereal t4;
extern doublereal t5;
extern doublereal t6;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize memory access to use consecutive indexing by precomputing base offsets
    integer base_idx;
    for (j = 1; j <= i__1; ++j) {
        base_idx = j * c_dim1;
        sum = v1 * c__[base_idx + 1] + v2 * c__[base_idx + 2] + v3 * c__[base_idx + 3] +
              v4 * c__[base_idx + 4] + v5 * c__[base_idx + 5] + v6 * c__[base_idx + 6];
        c__[base_idx + 1] -= sum * t1;
        c__[base_idx + 2] -= sum * t2;
        c__[base_idx + 3] -= sum * t3;
        c__[base_idx + 4] -= sum * t4;
        c__[base_idx + 5] -= sum * t5;
        c__[base_idx + 6] -= sum * t6;
    }
}
