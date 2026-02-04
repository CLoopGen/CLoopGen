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
extern doublereal t6;
extern doublereal t7;
extern doublereal t8;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal v8;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublereal local_t1 = t1, local_t2 = t2, local_t3 = t3, local_t4 = t4,
           local_t5 = t5, local_t6 = t6, local_t7 = t7, local_t8 = t8;
doublereal local_v1 = v1, local_v2 = v2, local_v3 = v3, local_v4 = v4,
           local_v5 = v5, local_v6 = v6, local_v7 = v7, local_v8 = v8;
for (j = 1; j <= i__1; ++j) {
    doublereal s1 = local_v1 * c__[j * c_dim1 + 1];
    doublereal s2 = local_v2 * c__[j * c_dim1 + 2];
    doublereal s3 = local_v3 * c__[j * c_dim1 + 3];
    doublereal s4 = local_v4 * c__[j * c_dim1 + 4];
    doublereal s5 = local_v5 * c__[j * c_dim1 + 5];
    doublereal s6 = local_v6 * c__[j * c_dim1 + 6];
    doublereal s7 = local_v7 * c__[j * c_dim1 + 7];
    doublereal s8 = local_v8 * c__[j * c_dim1 + 8];

    sum = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8;

    c__[j * c_dim1 + 1] = c__[j * c_dim1 + 1] - sum * local_t1;
    c__[j * c_dim1 + 2] = c__[j * c_dim1 + 2] - sum * local_t2;
    c__[j * c_dim1 + 3] = c__[j * c_dim1 + 3] - sum * local_t3;
    c__[j * c_dim1 + 4] = c__[j * c_dim1 + 4] - sum * local_t4;
    c__[j * c_dim1 + 5] = c__[j * c_dim1 + 5] - sum * local_t5;
    c__[j * c_dim1 + 6] = c__[j * c_dim1 + 6] - sum * local_t6;
    c__[j * c_dim1 + 7] = c__[j * c_dim1 + 7] - sum * local_t7;
    c__[j * c_dim1 + 8] = c__[j * c_dim1 + 8] - sum * local_t8;
}
}
