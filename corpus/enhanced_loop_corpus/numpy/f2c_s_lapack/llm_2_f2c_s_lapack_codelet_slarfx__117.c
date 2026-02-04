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
    // Variant 1: Consecutive Memory Access via Pointer Arithmetic
    // Instead of repeatedly calculating j + c_dim1*k, we precompute base pointers and step consecutively
    real *c1 = &c__[c_dim1 + 1];
    real *c2 = &c__[(c_dim1 << 1) + 1];
    real *c3 = &c__[c_dim1 * 3 + 1];
    real *c4 = &c__[(c_dim1 << 2) + 1];
    real *c5 = &c__[c_dim1 * 5 + 1];
    real *c6 = &c__[c_dim1 * 6 + 1];
    real *c7 = &c__[c_dim1 * 7 + 1];
    real *c8 = &c__[(c_dim1 << 3) + 1];
    real *c9 = &c__[c_dim1 * 9 + 1];
    real *c10 = &c__[c_dim1 * 10 + 1];

    for (j = 1; j <= i__1; ++j) {
        sum = v1 * c1[j] + v2 * c2[j] + v3 * c3[j] + v4 * c4[j] +
              v5 * c5[j] + v6 * c6[j] + v7 * c7[j] + v8 * c8[j] +
              v9 * c9[j] + v10 * c10[j];

        c1[j] -= sum * t1;
        c2[j] -= sum * t2;
        c3[j] -= sum * t3;
        c4[j] -= sum * t4;
        c5[j] -= sum * t5;
        c6[j] -= sum * t6;
        c7[j] -= sum * t7;
        c8[j] -= sum * t8;
        c9[j] -= sum * t9;
        c10[j] -= sum * t10;
    }
}
