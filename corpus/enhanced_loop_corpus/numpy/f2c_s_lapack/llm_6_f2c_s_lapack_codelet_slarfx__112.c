#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern real t1;
extern real t2;
extern real t3;
extern real t4;
extern real t5;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp1, temp2, temp3, temp4, temp5;
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
