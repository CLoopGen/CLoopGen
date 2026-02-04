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
    doublereal local_sum;
    for (j = 1; j <= i__1; ++j) {
        local_sum = v1 * c__[j + c_dim1];
        local_sum += v2 * c__[j + (c_dim1 << 1)];
        local_sum += v3 * c__[j + c_dim1 * 3];
        local_sum += v4 * c__[j + (c_dim1 << 2)];
        local_sum += v5 * c__[j + c_dim1 * 5];

        c__[j + c_dim1] = c__[j + c_dim1] - local_sum * t1;
        c__[j + (c_dim1 << 1)] = c__[j + (c_dim1 << 1)] - local_sum * t2;
        c__[j + c_dim1 * 3] = c__[j + c_dim1 * 3] - local_sum * t3;
        c__[j + (c_dim1 << 2)] = c__[j + (c_dim1 << 2)] - local_sum * t4;
        c__[j + c_dim1 * 5] = c__[j + c_dim1 * 5] - local_sum * t5;

        sum = local_sum;
    }
}
