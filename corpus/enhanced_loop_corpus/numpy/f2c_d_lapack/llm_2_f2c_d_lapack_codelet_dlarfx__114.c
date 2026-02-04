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
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    integer idx1 = j + c_dim1;
    integer idx2 = j + (c_dim1 << 1);
    integer idx3 = j + c_dim1 * 3;
    integer idx4 = j + (c_dim1 << 2);
    integer idx5 = j + c_dim1 * 5;
    integer idx6 = j + c_dim1 * 6;
    integer idx7 = j + c_dim1 * 7;

    sum = v1 * c__[idx1] + v2 * c__[idx2] + v3 * c__[idx3] + v4 * c__[idx4] + v5 * c__[idx5] + v6 * c__[idx6] + v7 * c__[idx7];
    c__[idx1] -= sum * t1;
    c__[idx2] -= sum * t2;
    c__[idx3] -= sum * t3;
    c__[idx4] -= sum * t4;
    c__[idx5] -= sum * t5;
    c__[idx6] -= sum * t6;
    c__[idx7] -= sum * t7;

    if (j + 1 <= i__1) {
        idx1 = j + 1 + c_dim1;
        idx2 = j + 1 + (c_dim1 << 1);
        idx3 = j + 1 + c_dim1 * 3;
        idx4 = j + 1 + (c_dim1 << 2);
        idx5 = j + 1 + c_dim1 * 5;
        idx6 = j + 1 + c_dim1 * 6;
        idx7 = j + 1 + c_dim1 * 7;

        sum = v1 * c__[idx1] + v2 * c__[idx2] + v3 * c__[idx3] + v4 * c__[idx4] + v5 * c__[idx5] + v6 * c__[idx6] + v7 * c__[idx7];
        c__[idx1] -= sum * t1;
        c__[idx2] -= sum * t2;
        c__[idx3] -= sum * t3;
        c__[idx4] -= sum * t4;
        c__[idx5] -= sum * t5;
        c__[idx6] -= sum * t6;
        c__[idx7] -= sum * t7;
    }
}
}
