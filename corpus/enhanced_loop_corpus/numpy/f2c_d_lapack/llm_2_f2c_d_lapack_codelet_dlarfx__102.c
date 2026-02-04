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
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    integer base_index = j * c_dim1;
    sum = v1 * c__[base_index + 1] + v2 * c__[base_index + 2] + v3 * c__[base_index + 3] + v4 * c__[base_index + 4] + v5 * c__[base_index + 5];
    c__[base_index + 1] -= sum * t1;
    c__[base_index + 2] -= sum * t2;
    c__[base_index + 3] -= sum * t3;
    c__[base_index + 4] -= sum * t4;
    c__[base_index + 5] -= sum * t5;
}
}
