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
doublereal prev_sum = 0.0;
for (j = 1; j <= i__1; ++j) {
    sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6] + v7 * c__[j + c_dim1 * 7] + v8 * c__[j + (c_dim1 << 3)] + v9 * c__[j + c_dim1 * 9];

    if (j > 1) {
        c__[j + c_dim1] -= prev_sum * t1;
        c__[j + (c_dim1 << 1)] -= prev_sum * t2;
        c__[j + c_dim1 * 3] -= prev_sum * t3;
        c__[j + (c_dim1 << 2)] -= prev_sum * t4;
        c__[j + c_dim1 * 5] -= prev_sum * t5;
        c__[j + c_dim1 * 6] -= prev_sum * t6;
        c__[j + c_dim1 * 7] -= prev_sum * t7;
        c__[j + (c_dim1 << 3)] -= prev_sum * t8;
        c__[j + c_dim1 * 9] -= prev_sum * t9;
    }

    prev_sum = sum;
}

if (i__1 >= 1) {
    c__[1 + c_dim1] -= sum * t1;
    c__[1 + (c_dim1 << 1)] -= sum * t2;
    c__[1 + c_dim1 * 3] -= sum * t3;
    c__[1 + (c_dim1 << 2)] -= sum * t4;
    c__[1 + c_dim1 * 5] -= sum * t5;
    c__[1 + c_dim1 * 6] -= sum * t6;
    c__[1 + c_dim1 * 7] -= sum * t7;
    c__[1 + (c_dim1 << 3)] -= sum * t8;
    c__[1 + c_dim1 * 9] -= sum * t9;
}
}
