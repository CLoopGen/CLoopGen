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
extern doublereal t9;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal v8;
extern doublereal v9;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations to access adjacent elements
    // We assume c_dim1 is known and stride can be exploited; here we process multiple j iterations at once
    // to improve spatial locality. This version unrolls the loop by 2 for better consecutive access.
    integer j;
    doublereal sum1, sum2;
    if (i__1 >= 2) {
        for (j = 1; j <= i__1 - 1; j += 2) {
            // Process j and j+1 together to enable consecutive accesses
            sum1 = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] +
                   v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6] +
                   v7 * c__[j + c_dim1 * 7] + v8 * c__[j + (c_dim1 << 3)] + v9 * c__[j + c_dim1 * 9];

            sum2 = v1 * c__[j+1 + c_dim1] + v2 * c__[j+1 + (c_dim1 << 1)] + v3 * c__[j+1 + c_dim1 * 3] +
                   v4 * c__[j+1 + (c_dim1 << 2)] + v5 * c__[j+1 + c_dim1 * 5] + v6 * c__[j+1 + c_dim1 * 6] +
                   v7 * c__[j+1 + c_dim1 * 7] + v8 * c__[j+1 + (c_dim1 << 3)] + v9 * c__[j+1 + c_dim1 * 9];

            // Update current and next index with improved cache reuse
            c__[j + c_dim1] -= sum1 * t1;
            c__[j + (c_dim1 << 1)] -= sum1 * t2;
            c__[j + c_dim1 * 3] -= sum1 * t3;
            c__[j + (c_dim1 << 2)] -= sum1 * t4;
            c__[j + c_dim1 * 5] -= sum1 * t5;
            c__[j + c_dim1 * 6] -= sum1 * t6;
            c__[j + c_dim1 * 7] -= sum1 * t7;
            c__[j + (c_dim1 << 3)] -= sum1 * t8;
            c__[j + c_dim1 * 9] -= sum1 * t9;

            c__[j+1 + c_dim1] -= sum2 * t1;
            c__[j+1 + (c_dim1 << 1)] -= sum2 * t2;
            c__[j+1 + c_dim1 * 3] -= sum2 * t3;
            c__[j+1 + (c_dim1 << 2)] -= sum2 * t4;
            c__[j+1 + c_dim1 * 5] -= sum2 * t5;
            c__[j+1 + c_dim1 * 6] -= sum2 * t6;
            c__[j+1 + c_dim1 * 7] -= sum2 * t7;
            c__[j+1 + (c_dim1 << 3)] -= sum2 * t8;
            c__[j+1 + c_dim1 * 9] -= sum2 * t9;
        }
        // Handle odd leftover element
        if (j <= i__1) {
            sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] +
                  v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6] +
                  v7 * c__[j + c_dim1 * 7] + v8 * c__[j + (c_dim1 << 3)] + v9 * c__[j + c_dim1 * 9];
            c__[j + c_dim1] -= sum * t1;
            c__[j + (c_dim1 << 1)] -= sum * t2;
            c__[j + c_dim1 * 3] -= sum * t3;
            c__[j + (c_dim1 << 2)] -= sum * t4;
            c__[j + c_dim1 * 5] -= sum * t5;
            c__[j + c_dim1 * 6] -= sum * t6;
            c__[j + c_dim1 * 7] -= sum * t7;
            c__[j + (c_dim1 << 3)] -= sum * t8;
            c__[j + c_dim1 * 9] -= sum * t9;
        }
    } else {
        for (j = 1; j <= i__1; ++j) {
            sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] +
                  v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6] +
                  v7 * c__[j + c_dim1 * 7] + v8 * c__[j + (c_dim1 << 3)] + v9 * c__[j + c_dim1 * 9];
            c__[j + c_dim1] -= sum * t1;
            c__[j + (c_dim1 << 1)] -= sum * t2;
            c__[j + c_dim1 * 3] -= sum * t3;
            c__[j + (c_dim1 << 2)] -= sum * t4;
            c__[j + c_dim1 * 5] -= sum * t5;
            c__[j + c_dim1 * 6] -= sum * t6;
            c__[j + c_dim1 * 7] -= sum * t7;
            c__[j + (c_dim1 << 3)] -= sum * t8;
            c__[j + c_dim1 * 9] -= sum * t9;
        }
    }
}
