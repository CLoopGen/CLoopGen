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
extern doublereal v1;
extern doublereal v2;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled by 2 for consecutive access pattern)
    integer j;
    doublereal sum1, sum2;
    for (j = 1; j <= i__1 - 1; j += 2) {
        sum1 = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)];
        sum2 = v1 * c__[j + 1 + c_dim1] + v2 * c__[j + 1 + (c_dim1 << 1)];
        
        c__[j + c_dim1] -= sum1 * t1;
        c__[j + (c_dim1 << 1)] -= sum1 * t2;
        
        c__[j + 1 + c_dim1] -= sum2 * t1;
        c__[j + 1 + (c_dim1 << 1)] -= sum2 * t2;
    }
    // Handle remaining element if i__1 is odd
    if (j <= i__1) {
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)];
        c__[j + c_dim1] -= sum * t1;
        c__[j + (c_dim1 << 1)] -= sum * t2;
    }
}
