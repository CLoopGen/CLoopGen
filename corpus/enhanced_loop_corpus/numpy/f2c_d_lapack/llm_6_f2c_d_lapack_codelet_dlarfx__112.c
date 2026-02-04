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
    doublereal temp1, temp2, temp3, temp4, temp5;
    for (j = 1; j <= i__1; ++j) {
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5];
        
        temp1 = sum * t1;
        temp2 = sum * t2;
        temp3 = sum * t3;
        temp4 = sum * t4;
        temp5 = sum * t5;

        c__[j + c_dim1] -= temp1;
        c__[j + (c_dim1 << 1)] -= temp2;
        c__[j + c_dim1 * 3] -= temp3;
        c__[j + (c_dim1 << 2)] -= temp4;
        c__[j + c_dim1 * 5] -= temp5;
    }
}
