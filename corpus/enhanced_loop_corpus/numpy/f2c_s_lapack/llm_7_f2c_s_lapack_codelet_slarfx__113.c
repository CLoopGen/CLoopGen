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
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_sum;
    for (j = 1; j <= i__1; ++j) {
        local_sum = v1 * c__[j + c_dim1];
        local_sum += v2 * c__[j + (c_dim1 << 1)];
        local_sum += v3 * c__[j + c_dim1 * 3];
        local_sum += v4 * c__[j + (c_dim1 << 2)];
        local_sum += v5 * c__[j + c_dim1 * 5];
        local_sum += v6 * c__[j + c_dim1 * 6];

        c__[j + c_dim1] = c__[j + c_dim1] - local_sum * t1;
        c__[j + (c_dim1 << 1)] = c__[j + (c_dim1 << 1)] - local_sum * t2;
        c__[j + c_dim1 * 3] = c__[j + c_dim1 * 3] - local_sum * t3;
        c__[j + (c_dim1 << 2)] = c__[j + (c_dim1 << 2)] - local_sum * t4;
        c__[j + c_dim1 * 5] = c__[j + c_dim1 * 5] - local_sum * t5;
        c__[j + c_dim1 * 6] = c__[j + c_dim1 * 6] - local_sum * t6;

        sum = local_sum;
    }
}
