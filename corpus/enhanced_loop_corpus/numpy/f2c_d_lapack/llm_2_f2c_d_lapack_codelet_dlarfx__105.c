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
extern doublereal t7;
extern doublereal t8;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal v8;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reordering computation to access adjacent elements
    // This variant assumes c_dim1 is large enough to allow consecutive access pattern in column-major layout
    integer offset;
    for (j = 1; j <= i__1; ++j) {
        offset = j * c_dim1 + 1;
        sum = v1 * c__[offset] + v2 * c__[offset + 1] + v3 * c__[offset + 2] + 
              v4 * c__[offset + 3] + v5 * c__[offset + 4] + v6 * c__[offset + 5] + 
              v7 * c__[offset + 6] + v8 * c__[offset + 7];
        
        c__[offset    ] -= sum * t1;
        c__[offset + 1] -= sum * t2;
        c__[offset + 2] -= sum * t3;
        c__[offset + 3] -= sum * t4;
        c__[offset + 4] -= sum * t5;
        c__[offset + 5] -= sum * t6;
        c__[offset + 6] -= sum * t7;
        c__[offset + 7] -= sum * t8;
    }
}
