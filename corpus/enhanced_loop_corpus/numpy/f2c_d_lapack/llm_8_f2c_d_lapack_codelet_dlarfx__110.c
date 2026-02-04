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
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer j_start = 1;
    integer j_step = 2;
    for (j = j_start; j <= i__1 - 1; j += j_step) {
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3];
        c__[j + c_dim1] -= sum * t1;
        c__[j + (c_dim1 << 1)] -= sum * t2;
        c__[j + c_dim1 * 3] -= sum * t3;

        sum = v1 * c__[j + 1 + c_dim1] + v2 * c__[j + 1 + (c_dim1 << 1)] + v3 * c__[j + 1 + c_dim1 * 3];
        c__[j + 1 + c_dim1] -= sum * t1;
        c__[j + 1 + (c_dim1 << 1)] -= sum * t2;
        c__[j + 1 + c_dim1 * 3] -= sum * t3;
    }
    if ((i__1 - j_start + 1) % 2 != 0) {
        j = i__1;
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3];
        c__[j + c_dim1] -= sum * t1;
        c__[j + (c_dim1 << 1)] -= sum * t2;
        c__[j + c_dim1 * 3] -= sum * t3;
    }
}
