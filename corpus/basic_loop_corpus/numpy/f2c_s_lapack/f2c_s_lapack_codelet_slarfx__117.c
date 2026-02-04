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
    sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6] + v7 * c__[j + c_dim1 * 7] + v8 * c__[j + (c_dim1 << 3)] + v9 * c__[j + c_dim1 * 9] + v10 * c__[j + c_dim1 * 10];
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
