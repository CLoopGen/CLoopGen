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
extern real t6;
extern real t7;
extern real t8;
extern real t9;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real v7;
extern real v8;
extern real v9;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
sum = 0.0f;
for (j = 1; j <= i__1; ++j) {
    real local_contrib = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6] + v7 * c__[j + c_dim1 * 7] + v8 * c__[j + (c_dim1 << 3)] + v9 * c__[j + c_dim1 * 9];
    sum += local_contrib;
    c__[j + c_dim1] -= local_contrib * t1;
    c__[j + (c_dim1 << 1)] -= local_contrib * t2;
    c__[j + c_dim1 * 3] -= local_contrib * t3;
    c__[j + (c_dim1 << 2)] -= local_contrib * t4;
    c__[j + c_dim1 * 5] -= local_contrib * t5;
    c__[j + c_dim1 * 6] -= local_contrib * t6;
    c__[j + c_dim1 * 7] -= local_contrib * t7;
    c__[j + (c_dim1 << 3)] -= local_contrib * t8;
    c__[j + c_dim1 * 9] -= local_contrib * t9;
}
sum /= i__1;
}
