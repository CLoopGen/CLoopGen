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
extern real t5;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop and increasing arithmetic operations per iteration
    integer j;
    real sum1, sum2, sum3, sum4;
    for (j = 1; j <= i__1 - 3; j += 4) {
        sum1 = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5];
        sum2 = v1 * c__[j + 1 + c_dim1] + v2 * c__[j + 1 + (c_dim1 << 1)] + v3 * c__[j + 1 + c_dim1 * 3] + v4 * c__[j + 1 + (c_dim1 << 2)] + v5 * c__[j + 1 + c_dim1 * 5];
        sum3 = v1 * c__[j + 2 + c_dim1] + v2 * c__[j + 2 + (c_dim1 << 1)] + v3 * c__[j + 2 + c_dim1 * 3] + v4 * c__[j + 2 + (c_dim1 << 2)] + v5 * c__[j + 2 + c_dim1 * 5];
        sum4 = v1 * c__[j + 3 + c_dim1] + v2 * c__[j + 3 + (c_dim1 << 1)] + v3 * c__[j + 3 + c_dim1 * 3] + v4 * c__[j + 3 + (c_dim1 << 2)] + v5 * c__[j + 3 + c_dim1 * 5];

        c__[j + c_dim1] -= sum1 * t1;
        c__[j + (c_dim1 << 1)] -= sum1 * t2;
        c__[j + c_dim1 * 3] -= sum1 * t3;
        c__[j + (c_dim1 << 2)] -= sum1 * t4;
        c__[j + c_dim1 * 5] -= sum1 * t5;

        c__[j + 1 + c_dim1] -= sum2 * t1;
        c__[j + 1 + (c_dim1 << 1)] -= sum2 * t2;
        c__[j + 1 + c_dim1 * 3] -= sum2 * t3;
        c__[j + 1 + (c_dim1 << 2)] -= sum2 * t4;
        c__[j + 1 + c_dim1 * 5] -= sum2 * t5;

        c__[j + 2 + c_dim1] -= sum3 * t1;
        c__[j + 2 + (c_dim1 << 1)] -= sum3 * t2;
        c__[j + 2 + c_dim1 * 3] -= sum3 * t3;
        c__[j + 2 + (c_dim1 << 2)] -= sum3 * t4;
        c__[j + 2 + c_dim1 * 5] -= sum3 * t5;

        c__[j + 3 + c_dim1] -= sum4 * t1;
        c__[j + 3 + (c_dim1 << 1)] -= sum4 * t2;
        c__[j + 3 + c_dim1 * 3] -= sum4 * t3;
        c__[j + 3 + (c_dim1 << 2)] -= sum4 * t4;
        c__[j + 3 + c_dim1 * 5] -= sum4 * t5;
    }
    // Handle remaining iterations
    for (; j <= i__1; ++j) {
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5];
        c__[j + c_dim1] -= sum * t1;
        c__[j + (c_dim1 << 1)] -= sum * t2;
        c__[j + c_dim1 * 3] -= sum * t3;
        c__[j + (c_dim1 << 2)] -= sum * t4;
        c__[j + c_dim1 * 5] -= sum * t5;
    }
}
