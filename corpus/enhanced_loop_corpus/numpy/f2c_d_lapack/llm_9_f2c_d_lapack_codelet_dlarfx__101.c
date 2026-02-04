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
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer inc = 2;
for (j = 1; j <= i__1; j += inc) {
    doublereal sum1, sum2;
    sum1 = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3] + v4 * c__[j * c_dim1 + 4];
    c__[j * c_dim1 + 1] -= sum1 * t1;
    c__[j * c_dim1 + 2] -= sum1 * t2;
    c__[j * c_dim1 + 3] -= sum1 * t3;
    c__[j * c_dim1 + 4] -= sum1 * t4;

    if (j + 1 <= i__1) {
        sum2 = v1 * c__[(j + 1) * c_dim1 + 1] + v2 * c__[(j + 1) * c_dim1 + 2] + 
               v3 * c__[(j + 1) * c_dim1 + 3] + v4 * c__[(j + 1) * c_dim1 + 4];
        c__[(j + 1) * c_dim1 + 1] -= sum2 * t1;
        c__[(j + 1) * c_dim1 + 2] -= sum2 * t2;
        c__[(j + 1) * c_dim1 + 3] -= sum2 * t3;
        c__[(j + 1) * c_dim1 + 4] -= sum2 * t4;
    }
}
}
