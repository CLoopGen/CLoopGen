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
    // Variant 2: Strided Access with Fixed Stride (simulate blocked/strided traversal)
    // Change access pattern to use a fixed stride across rows, processing multiple columns per iteration
    // This variant increases spatial locality by accessing nearby elements in memory when c_dim1 is large.

    integer stride = 4; // Process 4 consecutive j-values with fixed offset jumps
    integer limit = i__1 - (i__1 % stride); // Make sure we don't exceed bounds

    for (j = 1; j <= limit; j += stride) {
        // Handle four j-values in parallel using fixed offsets
        integer j1 = j;
        integer j2 = j + 1;
        integer j3 = j + 2;
        integer j4 = j + 3;

        // Compute sums for each j in the group (could be vectorized)
        doublereal sum1 = v1 * c__[j1 + c_dim1] + v2 * c__[j1 + (c_dim1 << 1)] +
                          v3 * c__[j1 + c_dim1 * 3] + v4 * c__[j1 + (c_dim1 << 2)] +
                          v5 * c__[j1 + c_dim1 * 5] + v6 * c__[j1 + c_dim1 * 6] +
                          v7 * c__[j1 + c_dim1 * 7] + v8 * c__[j1 + (c_dim1 << 3)];

        doublereal sum2 = v1 * c__[j2 + c_dim1] + v2 * c__[j2 + (c_dim1 << 1)] +
                          v3 * c__[j2 + c_dim1 * 3] + v4 * c__[j2 + (c_dim1 << 2)] +
                          v5 * c__[j2 + c_dim1 * 5] + v6 * c__[j2 + c_dim1 * 6] +
                          v7 * c__[j2 + c_dim1 * 7] + v8 * c__[j2 + (c_dim1 << 3)];

        doublereal sum3 = v1 * c__[j3 + c_dim1] + v2 * c__[j3 + (c_dim1 << 1)] +
                          v3 * c__[j3 + c_dim1 * 3] + v4 * c__[j3 + (c_dim1 << 2)] +
                          v5 * c__[j3 + c_dim1 * 5] + v6 * c__[j3 + c_dim1 * 6] +
                          v7 * c__[j3 + c_dim1 * 7] + v8 * c__[j3 + (c_dim1 << 3)];

        doublereal sum4 = v1 * c__[j4 + c_dim1] + v2 * c__[j4 + (c_dim1 << 1)] +
                          v3 * c__[j4 + c_dim1 * 3] + v4 * c__[j4 + (c_dim1 << 2)] +
                          v5 * c__[j4 + c_dim1 * 5] + v6 * c__[j4 + c_dim1 * 6] +
                          v7 * c__[j4 + c_dim1 * 7] + v8 * c__[j4 + (c_dim1 << 3)];

        // Update values for all four j's
        c__[j1 + c_dim1]         -= sum1 * t1;
        c__[j1 + (c_dim1 << 1)]  -= sum1 * t2;
        c__[j1 + c_dim1 * 3]     -= sum1 * t3;
        c__[j1 + (c_dim1 << 2)]  -= sum1 * t4;
        c__[j1 + c_dim1 * 5]     -= sum1 * t5;
        c__[j1 + c_dim1 * 6]     -= sum1 * t6;
        c__[j1 + c_dim1 * 7]     -= sum1 * t7;
        c__[j1 + (c_dim1 << 3)]  -= sum1 * t8;

        c__[j2 + c_dim1]         -= sum2 * t1;
        c__[j2 + (c_dim1 << 1)]  -= sum2 * t2;
        c__[j2 + c_dim1 * 3]     -= sum2 * t3;
        c__[j2 + (c_dim1 << 2)]  -= sum2 * t4;
        c__[j2 + c_dim1 * 5]     -= sum2 * t5;
        c__[j2 + c_dim1 * 6]     -= sum2 * t6;
        c__[j2 + c_dim1 * 7]     -= sum2 * t7;
        c__[j2 + (c_dim1 << 3)]  -= sum2 * t8;

        c__[j3 + c_dim1]         -= sum3 * t1;
        c__[j3 + (c_dim1 << 1)]  -= sum3 * t2;
        c__[j3 + c_dim1 * 3]     -= sum3 * t3;
        c__[j3 + (c_dim1 << 2)]  -= sum3 * t4;
        c__[j3 + c_dim1 * 5]     -= sum3 * t5;
        c__[j3 + c_dim1 * 6]     -= sum3 * t6;
        c__[j3 + c_dim1 * 7]     -= sum3 * t7;
        c__[j3 + (c_dim1 << 3)]  -= sum3 * t8;

        c__[j4 + c_dim1]         -= sum4 * t1;
        c__[j4 + (c_dim1 << 1)]  -= sum4 * t2;
        c__[j4 + c_dim1 * 3]     -= sum4 * t3;
        c__[j4 + (c_dim1 << 2)]  -= sum4 * t4;
        c__[j4 + c_dim1 * 5]     -= sum4 * t5;
        c__[j4 + c_dim1 * 6]     -= sum4 * t6;
        c__[j4 + c_dim1 * 7]     -= sum4 * t7;
        c__[j4 + (c_dim1 << 3)]  -= sum4 * t8;
    }

    // Cleanup loop for remaining elements
    for (; j <= i__1; ++j) {
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + 
              v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)] + 
              v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6] + 
              v7 * c__[j + c_dim1 * 7] + v8 * c__[j + (c_dim1 << 3)];
        c__[j + c_dim1]         -= sum * t1;
        c__[j + (c_dim1 << 1)]  -= sum * t2;
        c__[j + c_dim1 * 3]     -= sum * t3;
        c__[j + (c_dim1 << 2)]  -= sum * t4;
        c__[j + c_dim1 * 5]     -= sum * t5;
        c__[j + c_dim1 * 6]     -= sum * t6;
        c__[j + c_dim1 * 7]     -= sum * t7;
        c__[j + (c_dim1 << 3)]  -= sum * t8;
    }
}
