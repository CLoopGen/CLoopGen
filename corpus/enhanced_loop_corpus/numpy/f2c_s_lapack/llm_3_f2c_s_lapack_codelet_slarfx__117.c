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
extern real t7;
extern real t8;
extern real t9;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real v7;
extern real v8;
extern real v9;
extern real t10;
extern real v10;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access with Fixed Increment
    // Access memory using a fixed stride derived from c_dim1, stepping through j in larger increments if possible
    // Here we maintain the same logic but restructure indexing to emphasize strided access patterns
    // We also unroll the loop by a factor of 2 for improved stride utilization and performance

    integer stride = c_dim1;
    integer limit = i__1 - 1;  // Adjust for unrolling by 2

    for (j = 1; j <= limit; j += 2) {
        // First element (j)
        sum = v1 * c__[j + stride] + v2 * c__[j + (stride << 1)] +
              v3 * c__[j + stride * 3] + v4 * c__[j + (stride << 2)] +
              v5 * c__[j + stride * 5] + v6 * c__[j + stride * 6] +
              v7 * c__[j + stride * 7] + v8 * c__[j + (stride << 3)] +
              v9 * c__[j + stride * 9] + v10 * c__[j + stride * 10];

        c__[j + stride] -= sum * t1;
        c__[j + (stride << 1)] -= sum * t2;
        c__[j + stride * 3] -= sum * t3;
        c__[j + (stride << 2)] -= sum * t4;
        c__[j + stride * 5] -= sum * t5;
        c__[j + stride * 6] -= sum * t6;
        c__[j + stride * 7] -= sum * t7;
        c__[j + (stride << 3)] -= sum * t8;
        c__[j + stride * 9] -= sum * t9;
        c__[j + stride * 10] -= sum * t10;

        // Second element (j+1)
        sum = v1 * c__[j + 1 + stride] + v2 * c__[j + 1 + (stride << 1)] +
              v3 * c__[j + 1 + stride * 3] + v4 * c__[j + 1 + (stride << 2)] +
              v5 * c__[j + 1 + stride * 5] + v6 * c__[j + 1 + stride * 6] +
              v7 * c__[j + 1 + stride * 7] + v8 * c__[j + 1 + (stride << 3)] +
              v9 * c__[j + 1 + stride * 9] + v10 * c__[j + 1 + stride * 10];

        c__[j + 1 + stride] -= sum * t1;
        c__[j + 1 + (stride << 1)] -= sum * t2;
        c__[j + 1 + stride * 3] -= sum * t3;
        c__[j + 1 + (stride << 2)] -= sum * t4;
        c__[j + 1 + stride * 5] -= sum * t5;
        c__[j + 1 + stride * 6] -= sum * t6;
        c__[j + 1 + stride * 7] -= sum * t7;
        c__[j + 1 + (stride << 3)] -= sum * t8;
        c__[j + 1 + stride * 9] -= sum * t9;
        c__[j + 1 + stride * 10] -= sum * t10;
    }

    // Handle remaining element if i__1 is odd
    if (j <= i__1) {
        sum = v1 * c__[j + stride] + v2 * c__[j + (stride << 1)] +
              v3 * c__[j + stride * 3] + v4 * c__[j + (stride << 2)] +
              v5 * c__[j + stride * 5] + v6 * c__[j + stride * 6] +
              v7 * c__[j + stride * 7] + v8 * c__[j + (stride << 3)] +
              v9 * c__[j + stride * 9] + v10 * c__[j + stride * 10];

        c__[j + stride] -= sum * t1;
        c__[j + (stride << 1)] -= sum * t2;
        c__[j + stride * 3] -= sum * t3;
        c__[j + (stride << 2)] -= sum * t4;
        c__[j + stride * 5] -= sum * t5;
        c__[j + stride * 6] -= sum * t6;
        c__[j + stride * 7] -= sum * t7;
        c__[j + (stride << 3)] -= sum * t8;
        c__[j + stride * 9] -= sum * t9;
        c__[j + stride * 10] -= sum * t10;
    }
}
