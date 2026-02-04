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



void loop(){
for (j = 1; j <= i__1; ++j) {
    for (integer factor = 1; factor <= 10; ++factor) {
        if (factor == 1) {
            sum = v1 * c__[j + c_dim1 * factor];
        } else if (factor == 2) {
            sum += v2 * c__[j + (c_dim1 << 1)];
        } else if (factor == 3) {
            sum += v3 * c__[j + c_dim1 * 3];
        } else if (factor == 4) {
            sum += v4 * c__[j + (c_dim1 << 2)];
        } else if (factor == 5) {
            sum += v5 * c__[j + c_dim1 * 5];
        } else if (factor == 6) {
            sum += v6 * c__[j + c_dim1 * 6];
        } else if (factor == 7) {
            sum += v7 * c__[j + c_dim1 * 7];
        } else if (factor == 8) {
            sum += v8 * c__[j + (c_dim1 << 3)];
        } else if (factor == 9) {
            sum += v9 * c__[j + c_dim1 * 9];
        } else if (factor == 10) {
            sum += v10 * c__[j + c_dim1 * 10];
        }
    }
    c__[j + c_dim1] -= sum * t1;
    c__[j + (c_dim1 << 1)] -= sum * t2;
    c__[j + c_dim1 * 3] -= sum * t3;
    c__[j + (c_dim1 << 2)] -= sum * t4;
    c__[j + c_dim1 * 5] -= sum * t5;
    c__[j + c_dim1 * 6] -= sum * t6;
    c__[j + c_dim1 * 7] -= sum * t7;
    c__[j + (c_dim1 << 3)] -= sum * t8;
    c__[j + c_dim1 * 9] -= sum * t9;
    c__[j + c_dim1 * 10] -= sum * t10;
}
}
