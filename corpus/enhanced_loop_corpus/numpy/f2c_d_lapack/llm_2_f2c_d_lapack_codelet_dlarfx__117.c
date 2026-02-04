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
extern doublereal t10;
extern doublereal v10;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    doublereal sum1 = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6] + v7 * c__[j + c_dim1 * 7] + v8 * c__[j + (c_dim1 << 3)] + v9 * c__[j + c_dim1 * 9] + v10 * c__[j + c_dim1 * 10];
    doublereal sum2 = 0.0;
    if (j + 1 <= i__1) {
        sum2 = v1 * c__[j + 1 + c_dim1] + v2 * c__[j + 1 + (c_dim1 << 1)] + v3 * c__[j + 1 + c_dim1 * 3] + v4 * c__[j + 1 + (c_dim1 << 2)] + v5 * c__[j + 1 + c_dim1 * 5] + v6 * c__[j + 1 + c_dim1 * 6] + v7 * c__[j + 1 + c_dim1 * 7] + v8 * c__[j + 1 + (c_dim1 << 3)] + v9 * c__[j + 1 + c_dim1 * 9] + v10 * c__[j + 1 + c_dim1 * 10];
    }
    c__[j + c_dim1] -= sum1 * t1;
    c__[j + (c_dim1 << 1)] -= sum1 * t2;
    c__[j + c_dim1 * 3] -= sum1 * t3;
    c__[j + (c_dim1 << 2)] -= sum1 * t4;
    c__[j + c_dim1 * 5] -= sum1 * t5;
    c__[j + c_dim1 * 6] -= sum1 * t6;
    c__[j + c_dim1 * 7] -= sum1 * t7;
    c__[j + (c_dim1 << 3)] -= sum1 * t8;
    c__[j + c_dim1 * 9] -= sum1 * t9;
    c__[j + c_dim1 * 10] -= sum1 * t10;

    if (j + 1 <= i__1) {
        c__[j + 1 + c_dim1] -= sum2 * t1;
        c__[j + 1 + (c_dim1 << 1)] -= sum2 * t2;
        c__[j + 1 + c_dim1 * 3] -= sum2 * t3;
        c__[j + 1 + (c_dim1 << 2)] -= sum2 * t4;
        c__[j + 1 + c_dim1 * 5] -= sum2 * t5;
        c__[j + 1 + c_dim1 * 6] -= sum2 * t6;
        c__[j + 1 + c_dim1 * 7] -= sum2 * t7;
        c__[j + 1 + (c_dim1 << 3)] -= sum2 * t8;
        c__[j + 1 + c_dim1 * 9] -= sum2 * t9;
        c__[j + 1 + c_dim1 * 10] -= sum2 * t10;
    }
}
}
