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
    // Variant 1: Consecutive Memory Access via Reordering and Temporary Array
    doublereal temp[6];
    for (j = 1; j <= i__1; ++j) {
        // Load accessed elements into a temporary array with consecutive access pattern
        temp[0] = c__[j + c_dim1];
        temp[1] = c__[j + (c_dim1 << 1)];
        temp[2] = c__[j + c_dim1 * 3];
        temp[3] = c__[j + (c_dim1 << 2)];
        temp[4] = c__[j + c_dim1 * 5];
        temp[5] = c__[j + c_dim1 * 6];

        sum = v1 * temp[0] + v2 * temp[1] + v3 * temp[2] + v4 * temp[3] + v5 * temp[4] + v6 * temp[5];

        // Update original locations using the same reordered access
        c__[j + c_dim1]         -= sum * t1;
        c__[j + (c_dim1 << 1)]  -= sum * t2;
        c__[j + c_dim1 * 3]     -= sum * t3;
        c__[j + (c_dim1 << 2)]  -= sum * t4;
        c__[j + c_dim1 * 5]     -= sum * t5;
        c__[j + c_dim1 * 6]     -= sum * t6;
    }
}
