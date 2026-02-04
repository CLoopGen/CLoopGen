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
integer stride = c_dim1;
integer offsets[7];
offsets[0] = stride;
offsets[1] = stride << 1;
offsets[2] = stride * 3;
offsets[3] = stride << 2;
offsets[4] = stride * 5;
offsets[5] = stride * 6;
offsets[6] = stride * 7;

for (j = 1; j <= i__1; ++j) {
    doublereal temp_vals[7];
    for (integer k = 0; k < 7; ++k) {
        temp_vals[k] = c__[j + offsets[k]];
    }

    sum = v1 * temp_vals[0] + v2 * temp_vals[1] + v3 * temp_vals[2] + 
          v4 * temp_vals[3] + v5 * temp_vals[4] + v6 * temp_vals[5] + 
          v7 * temp_vals[6];

    c__[j + offsets[0]] -= sum * t1;
    c__[j + offsets[1]] -= sum * t2;
    c__[j + offsets[2]] -= sum * t3;
    c__[j + offsets[3]] -= sum * t4;
    c__[j + offsets[4]] -= sum * t5;
    c__[j + offsets[5]] -= sum * t6;
    c__[j + offsets[6]] -= sum * t7;
}
}
