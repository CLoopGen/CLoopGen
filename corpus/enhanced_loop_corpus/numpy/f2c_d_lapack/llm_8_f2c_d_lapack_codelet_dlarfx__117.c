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
    sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)];
    c__[j + c_dim1] -= sum * t1;
    if (j + 1 <= i__1) {
        sum = v1 * c__[j + 1 + c_dim1] + v2 * c__[j + 1 + (c_dim1 << 1)];
        c__[j + 1 + c_dim1] -= sum * t1;
    }
}
}
