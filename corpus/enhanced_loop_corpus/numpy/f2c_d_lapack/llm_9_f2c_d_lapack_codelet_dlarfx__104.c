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
integer factor = 4;
for (j = 1; j <= i__1 && j <= 100; ++j) {
    sum = (v1 + v2 + v3) * (c__[j * c_dim1 + 1] + c__[j * c_dim1 + 2] + c__[j * c_dim1 + 3]) +
          (v4 + v5 + v6 + v7) * (c__[j * c_dim1 + 4] + c__[j * c_dim1 + 5] + c__[j * c_dim1 + 6] + c__[j * c_dim1 + 7]);
    sum *= 0.5;

    c__[j * c_dim1 + 1] -= sum * t1 / factor;
    c__[j * c_dim1 + 2] -= sum * t2 / factor;
    c__[j * c_dim1 + 3] -= sum * t3 / factor;
    c__[j * c_dim1 + 4] -= sum * t4 / factor;
    c__[j * c_dim1 + 5] -= sum * t5 / factor;
    c__[j * c_dim1 + 6] -= sum * t6 / factor;
    c__[j * c_dim1 + 7] -= sum * t7 / factor;
}
}
