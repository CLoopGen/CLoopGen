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
for (j = 1; j <= i__1; ++j) {
    integer base_index = j * c_dim1;
    sum = v1 * c__[base_index + 1] + v2 * c__[base_index + 2] + v3 * c__[base_index + 3] + v4 * c__[base_index + 4] + 
          v5 * c__[base_index + 5] + v6 * c__[base_index + 6] + v7 * c__[base_index + 7] + v8 * c__[base_index + 8] + 
          v9 * c__[base_index + 9] + v10 * c__[base_index + 10];
    c__[base_index + 1] -= sum * t1;
    c__[base_index + 2] -= sum * t2;
    c__[base_index + 3] -= sum * t3;
    c__[base_index + 4] -= sum * t4;
    c__[base_index + 5] -= sum * t5;
    c__[base_index + 6] -= sum * t6;
    c__[base_index + 7] -= sum * t7;
    c__[base_index + 8] -= sum * t8;
    c__[base_index + 9] -= sum * t9;
    c__[base_index + 10] -= sum * t10;
}
}
