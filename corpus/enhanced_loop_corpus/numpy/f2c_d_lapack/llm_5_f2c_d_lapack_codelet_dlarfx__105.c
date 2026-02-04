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
for (j = 1; j <= i__1; ++j) {
    sum = 0.0;
    if (j > i__1 / 2) {
        sum += v1 * c__[j * c_dim1 + 1];
        sum += v2 * c__[j * c_dim1 + 2];
        sum += v3 * c__[j * c_dim1 + 3];
        sum += v4 * c__[j * c_dim1 + 4];
        sum += v5 * c__[j * c_dim1 + 5];
        sum += v6 * c__[j * c_dim1 + 6];
        sum += v7 * c__[j * c_dim1 + 7];
        sum += v8 * c__[j * c_dim1 + 8];
    } else {
        sum = v4 * c__[j * c_dim1 + 4] + v5 * c__[j * c_dim1 + 5];
    }
    c__[j * c_dim1 + 1] -= sum * t1;
    c__[j * c_dim1 + 2] -= sum * t2;
    c__[j * c_dim1 + 3] -= sum * t3;
    c__[j * c_dim1 + 4] -= sum * t4;
    c__[j * c_dim1 + 5] -= sum * t5;
    c__[j * c_dim1 + 6] -= sum * t6;
    c__[j * c_dim1 + 7] -= sum * t7;
    c__[j * c_dim1 + 8] -= sum * t8;
}
}
