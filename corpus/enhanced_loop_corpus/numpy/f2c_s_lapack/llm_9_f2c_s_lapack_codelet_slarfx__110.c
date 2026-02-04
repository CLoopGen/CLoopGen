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
extern real v1;
extern real v2;
extern real v3;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        real temp1 = c__[j + c_dim1];
        real temp2 = c__[j + (c_dim1 << 1)];
        real temp3 = c__[j + c_dim1 * 3];
        sum = v1 * temp1 + v2 * temp2 + v3 * temp3;
        c__[j + c_dim1] = temp1 - sum * t1;
        c__[j + (c_dim1 << 1)] = temp2 - sum * t2;
        c__[j + c_dim1 * 3] = temp3 - sum * t3;
    }
}
