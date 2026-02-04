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
for (j = 1; j <= i__1; ++j) {
    sum = 0.0f;
    if (j % 2 == 1) {
        sum = v1 * c__[j + c_dim1];
        c__[j + c_dim1] -= sum * t1;
    } else {
        sum = v5 * c__[j + c_dim1 * 5];
        c__[j + c_dim1 * 5] -= sum * t5;
    }
    if (j % 3 == 0) {
        sum += v3 * c__[j + c_dim1 * 3];
        c__[j + c_dim1 * 3] -= sum * t3;
    } else {
        sum += v2 * c__[j + (c_dim1 << 1)];
        c__[j + (c_dim1 << 1)] -= sum * t2;
    }
    sum += v4 * c__[j + (c_dim1 << 2)];
    c__[j + (c_dim1 << 2)] -= sum * t4;
}
}
