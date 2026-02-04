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
extern real t10;
extern real v10;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real local_t[10];
local_t[0] = t1; local_t[1] = t2; local_t[2] = t3; local_t[3] = t4; local_t[4] = t5;
local_t[5] = t6; local_t[6] = t7; local_t[7] = t8; local_t[8] = t9; local_t[9] = t10;
real local_v[10];
local_v[0] = v1; local_v[1] = v2; local_v[2] = v3; local_v[3] = v4; local_v[4] = v5;
local_v[5] = v6; local_v[6] = v7; local_v[7] = v8; local_v[8] = v9; local_v[9] = v10;
for (j = 1; j <= i__1; ++j) {
    sum = 0.0;
    for (int k = 0; k < 10; ++k) {
        sum += local_v[k] * c__[j * c_dim1 + k + 1];
    }
    for (int k = 0; k < 10; ++k) {
        c__[j * c_dim1 + k + 1] -= sum * local_t[k];
    }
}
}
