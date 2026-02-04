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
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real v7;
extern real v8;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    real temp[8];
    for (j = 1; j <= i__1; ++j) {
        // Introduce temporary storage to remove immediate write-after-write (WAW) and write-after-read (WAR)
        // dependencies by decoupling reads from writes.
        temp[0] = c__[j + c_dim1];
        temp[1] = c__[j + (c_dim1 << 1)];
        temp[2] = c__[j + c_dim1 * 3];
        temp[3] = c__[j + (c_dim1 << 2)];
        temp[4] = c__[j + c_dim1 * 5];
        temp[5] = c__[j + c_dim1 * 6];
        temp[6] = c__[j + c_dim1 * 7];
        temp[7] = c__[j + (c_dim1 << 3)];

        sum = v1 * temp[0] + v2 * temp[1] + v3 * temp[2] + v4 * temp[3] +
              v5 * temp[4] + v6 * temp[5] + v7 * temp[6] + v8 * temp[7];

        // Now perform all updates using the cached values — eliminates potential
        // RAW hazards due to self-modification in same iteration.
        c__[j + c_dim1] = temp[0] - sum * t1;
        c__[j + (c_dim1 << 1)] = temp[1] - sum * t2;
        c__[j + c_dim1 * 3] = temp[2] - sum * t3;
        c__[j + (c_dim1 << 2)] = temp[3] - sum * t4;
        c__[j + c_dim1 * 5] = temp[4] - sum * t5;
        c__[j + c_dim1 * 6] = temp[5] - sum * t6;
        c__[j + c_dim1 * 7] = temp[6] - sum * t7;
        c__[j + (c_dim1 << 3)] = temp[7] - sum * t8;
    }
}
