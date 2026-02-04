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
for (j = 1; j <= i__1; ++j) {
    doublereal temp1 = v1 * c__[j + c_dim1];
    doublereal temp2 = v2 * c__[j + (c_dim1 << 1)];
    doublereal temp3 = v3 * c__[j + c_dim1 * 3];
    doublereal temp4 = v4 * c__[j + (c_dim1 << 2)];
    doublereal temp5 = v5 * c__[j + c_dim1 * 5];
    doublereal temp6 = v6 * c__[j + c_dim1 * 6];
    doublereal temp7 = v7 * c__[j + c_dim1 * 7];
    doublereal temp8 = v8 * c__[j + (c_dim1 << 3)];
    doublereal temp9 = v9 * c__[j + c_dim1 * 9];

    sum = temp1 + temp2 + temp3 + temp4 + temp5 + temp6 + temp7 + temp8 + temp9;

    doublereal s_t1 = sum * t1;
    doublereal s_t2 = sum * t2;
    doublereal s_t3 = sum * t3;
    doublereal s_t4 = sum * t4;
    doublereal s_t5 = sum * t5;
    doublereal s_t6 = sum * t6;
    doublereal s_t7 = sum * t7;
    doublereal s_t8 = sum * t8;
    doublereal s_t9 = sum * t9;

    c__[j + c_dim1] -= s_t1;
    c__[j + (c_dim1 << 1)] -= s_t2;
    c__[j + c_dim1 * 3] -= s_t3;
    c__[j + (c_dim1 << 2)] -= s_t4;
    c__[j + c_dim1 * 5] -= s_t5;
    c__[j + c_dim1 * 6] -= s_t6;
    c__[j + c_dim1 * 7] -= s_t7;
    c__[j + (c_dim1 << 3)] -= s_t8;
    c__[j + c_dim1 * 9] -= s_t9;
}
}
