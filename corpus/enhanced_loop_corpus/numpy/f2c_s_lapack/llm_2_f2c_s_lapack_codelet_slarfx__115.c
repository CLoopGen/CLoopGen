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
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real v7;
extern real v8;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    integer idx1 = j + c_dim1;
    integer idx2 = j + (c_dim1 << 1);
    integer idx3 = j + c_dim1 * 3;
    integer idx4 = j + (c_dim1 << 2);
    integer idx5 = j + c_dim1 * 5;
    integer idx6 = j + c_dim1 * 6;
    integer idx7 = j + c_dim1 * 7;
    integer idx8 = j + (c_dim1 << 3);

    sum = v1 * c__[idx1] + v2 * c__[idx2] + v3 * c__[idx3] + v4 * c__[idx4] + 
          v5 * c__[idx5] + v6 * c__[idx6] + v7 * c__[idx7] + v8 * c__[idx8];

    c__[idx1] -= sum * t1;
    c__[idx2] -= sum * t2;
    c__[idx3] -= sum * t3;
    c__[idx4] -= sum * t4;
    c__[idx5] -= sum * t5;
    c__[idx6] -= sum * t6;
    c__[idx7] -= sum * t7;
    c__[idx8] -= sum * t8;
}
}
