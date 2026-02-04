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
    for (j = 1; j <= i__1; ++j) {
        real s1 = v1 * c__[j * c_dim1 + 1];
        real s2 = v2 * c__[j * c_dim1 + 2];
        real s3 = v3 * c__[j * c_dim1 + 3];
        real s4 = v4 * c__[j * c_dim1 + 4];
        real s5 = v5 * c__[j * c_dim1 + 5];

        sum = s1 + s2 + s3 + s4 + s5;

        real update1 = sum * t1;
        real update2 = sum * t2;
        real update3 = sum * t3;
        real update4 = sum * t4;
        real update5 = sum * t5;

        c__[j * c_dim1 + 1] = c__[j * c_dim1 + 1] - update1;
        c__[j * c_dim1 + 2] = c__[j * c_dim1 + 2] - update2;
        c__[j * c_dim1 + 3] = c__[j * c_dim1 + 3] - update3;
        c__[j * c_dim1 + 4] = c__[j * c_dim1 + 4] - update4;
        c__[j * c_dim1 + 5] = c__[j * c_dim1 + 5] - update5;
    }
}
