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
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_sum[3] = {0.0};
    for (j = 1; j <= i__1; ++j) {
        sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3];
        local_sum[0] = sum * t1;
        local_sum[1] = sum * t2;
        local_sum[2] = sum * t3;
        c__[j * c_dim1 + 1] -= local_sum[0];
        c__[j * c_dim1 + 2] -= local_sum[1];
        c__[j * c_dim1 + 3] -= local_sum[2];
    }
}
