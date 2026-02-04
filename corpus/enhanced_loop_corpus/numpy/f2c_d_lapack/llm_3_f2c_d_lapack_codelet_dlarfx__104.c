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
for (j = 1; j <= i__1; ++j) {
    integer offset = j * c_dim1;
    doublereal temp[7];
    for (integer k = 0; k < 7; ++k) {
        temp[k] = c__[offset + (k + 1)];
    }
    sum = v1 * temp[0] + v2 * temp[1] + v3 * temp[2] + 
          v4 * temp[3] + v5 * temp[4] + v6 * temp[5] + 
          v7 * temp[6];
    for (integer k = 0; k < 7; ++k) {
        c__[offset + (k + 1)] -= sum * ((doublereal[]){t1, t2, t3, t4, t5, t6, t7})[k];
    }
}
}
