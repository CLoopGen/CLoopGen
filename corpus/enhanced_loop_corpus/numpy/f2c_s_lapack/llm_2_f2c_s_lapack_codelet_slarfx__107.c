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
for (j = 1; j <= i__1; ++j) {
    real *base = &c__[j * c_dim1 + 1];
    sum = v1 * base[0] + v2 * base[1] + v3 * base[2] + v4 * base[3] + v5 * base[4] 
        + v6 * base[5] + v7 * base[6] + v8 * base[7] + v9 * base[8] + v10 * base[9];
    base[0] -= sum * t1;
    base[1] -= sum * t2;
    base[2] -= sum * t3;
    base[3] -= sum * t4;
    base[4] -= sum * t5;
    base[5] -= sum * t6;
    base[6] -= sum * t7;
    base[7] -= sum * t8;
    base[8] -= sum * t9;
    base[9] -= sum * t10;
}
}
