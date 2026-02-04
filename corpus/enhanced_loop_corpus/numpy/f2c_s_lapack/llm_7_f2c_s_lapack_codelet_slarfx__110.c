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
    real sum1, sum2, sum3;
    sum1 = sum2 = sum3 = 0.0f;
    for (j = 1; j <= i__1; ++j) {
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3];
        sum1 += sum * t1;
        sum2 += sum * t2;
        sum3 += sum * t3;
        c__[j + c_dim1] -= sum * t1;
    }
    for (j = 1; j <= i__1; ++j) {
        c__[j + (c_dim1 << 1)] -= sum2;
        c__[j + c_dim1 * 3] -= sum3;
    }
}
