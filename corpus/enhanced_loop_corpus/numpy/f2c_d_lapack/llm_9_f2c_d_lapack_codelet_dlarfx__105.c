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
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal v8;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
sum = 0.0;
for (j = 1; j <= i__1 / 2; ++j) {
    doublereal temp1 = c__[j * c_dim1 + 1];
    doublereal temp2 = c__[j * c_dim1 + 2];
    doublereal temp3 = c__[j * c_dim1 + 3];
    doublereal temp4 = c__[j * c_dim1 + 4];
    doublereal temp5 = c__[j * c_dim1 + 5];
    doublereal temp6 = c__[j * c_dim1 + 6];
    doublereal temp7 = c__[j * c_dim1 + 7];
    doublereal temp8 = c__[j * c_dim1 + 8];

    sum += v1 * temp1 + v2 * temp2 + v3 * temp3 + v4 * temp4 +
           v5 * temp5 + v6 * temp6 + v7 * temp7 + v8 * temp8;

    c__[j * c_dim1 + 1] = temp1 - sum * t1;
    c__[j * c_dim1 + 2] = temp2 - sum * t2;
    c__[j * c_dim1 + 3] = temp3 - sum * t3;
    c__[j * c_dim1 + 4] = temp4 - sum * t4;
    c__[j * c_dim1 + 5] = temp5 - sum * t5;
    c__[j * c_dim1 + 6] = temp6 - sum * t6;
    c__[j * c_dim1 + 7] = temp7 - sum * t7;
    c__[j * c_dim1 + 8] = temp8 - sum * t8;
}
}
