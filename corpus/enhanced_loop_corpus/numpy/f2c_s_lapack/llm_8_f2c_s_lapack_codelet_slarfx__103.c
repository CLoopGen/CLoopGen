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
extern real t6;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop and increasing arithmetic operations per iteration
    // The trip count is reduced by partially unrolling with a factor of 2, assuming i__1 is even for simplicity.
    integer j;
    real sum1, sum2;

    for (j = 1; j <= i__1 - 1; j += 2) {
        // First iteration of unrolled pair
        sum1 = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3] +
               v4 * c__[j * c_dim1 + 4] + v5 * c__[j * c_dim1 + 5] + v6 * c__[j * c_dim1 + 6];
        c__[j * c_dim1 + 1] -= sum1 * t1;
        c__[j * c_dim1 + 2] -= sum1 * t2;
        c__[j * c_dim1 + 3] -= sum1 * t3;
        c__[j * c_dim1 + 4] -= sum1 * t4;
        c__[j * c_dim1 + 5] -= sum1 * t5;
        c__[j * c_dim1 + 6] -= sum1 * t6;

        // Second iteration of unrolled pair
        sum2 = v1 * c__[(j+1) * c_dim1 + 1] + v2 * c__[(j+1) * c_dim1 + 2] + v3 * c__[(j+1) * c_dim1 + 3] +
               v4 * c__[(j+1) * c_dim1 + 4] + v5 * c__[(j+1) * c_dim1 + 5] + v6 * c__[(j+1) * c_dim1 + 6];
        c__[(j+1) * c_dim1 + 1] -= sum2 * t1;
        c__[(j+1) * c_dim1 + 2] -= sum2 * t2;
        c__[(j+1) * c_dim1 + 3] -= sum2 * t3;
        c__[(j+1) * c_dim1 + 4] -= sum2 * t4;
        c__[(j+1) * c_dim1 + 5] -= sum2 * t5;
        c__[(j+1) * c_dim1 + 6] -= sum2 * t6;
    }

    // Handle remaining iteration if i__1 is odd
    if (j <= i__1) {
        sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3] +
              v4 * c__[j * c_dim1 + 4] + v5 * c__[j * c_dim1 + 5] + v6 * c__[j * c_dim1 + 6];
        c__[j * c_dim1 + 1] -= sum * t1;
        c__[j * c_dim1 + 2] -= sum * t2;
        c__[j * c_dim1 + 3] -= sum * t3;
        c__[j * c_dim1 + 4] -= sum * t4;
        c__[j * c_dim1 + 5] -= sum * t5;
        c__[j * c_dim1 + 6] -= sum * t6;
    }
}
