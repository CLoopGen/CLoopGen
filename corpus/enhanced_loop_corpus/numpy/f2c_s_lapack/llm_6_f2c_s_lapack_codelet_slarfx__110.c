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
    real temp_sum;
    for (j = 1; j <= i__1; ++j) {
        temp_sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3];
        c__[j + c_dim1] = c__[j + c_dim1] - temp_sum * t1;
        c__[j + (c_dim1 << 1)] = c__[j + (c_dim1 << 1)] - temp_sum * t2;
        c__[j + c_dim1 * 3] = c__[j + c_dim1 * 3] - temp_sum * t3;
    }
}
