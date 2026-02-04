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
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real v7;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    integer index1 = j * c_dim1;
    integer index2 = (j + 1) * c_dim1;
    if (j + 1 <= i__1) {
        sum = v1 * c__[index1 + 1] + v2 * c__[index1 + 2] + v3 * c__[index1 + 3] + 
              v4 * c__[index1 + 4] + v5 * c__[index1 + 5] + v6 * c__[index1 + 6] + 
              v7 * c__[index1 + 7];
        c__[index1 + 1] -= sum * t1;
        c__[index1 + 2] -= sum * t2;
        c__[index1 + 3] -= sum * t3;
        c__[index1 + 4] -= sum * t4;
        c__[index1 + 5] -= sum * t5;
        c__[index1 + 6] -= sum * t6;
        c__[index1 + 7] -= sum * t7;

        sum = v1 * c__[index2 + 1] + v2 * c__[index2 + 2] + v3 * c__[index2 + 3] + 
              v4 * c__[index2 + 4] + v5 * c__[index2 + 5] + v6 * c__[index2 + 6] + 
              v7 * c__[index2 + 7];
        c__[index2 + 1] -= sum * t1;
        c__[index2 + 2] -= sum * t2;
        c__[index2 + 3] -= sum * t3;
        c__[index2 + 4] -= sum * t4;
        c__[index2 + 5] -= sum * t5;
        c__[index2 + 6] -= sum * t6;
        c__[index2 + 7] -= sum * t7;
    } else {
        sum = v1 * c__[index1 + 1] + v2 * c__[index1 + 2] + v3 * c__[index1 + 3] + 
              v4 * c__[index1 + 4] + v5 * c__[index1 + 5] + v6 * c__[index1 + 6] + 
              v7 * c__[index1 + 7];
        c__[index1 + 1] -= sum * t1;
        c__[index1 + 2] -= sum * t2;
        c__[index1 + 3] -= sum * t3;
        c__[index1 + 4] -= sum * t4;
        c__[index1 + 5] -= sum * t5;
        c__[index1 + 6] -= sum * t6;
        c__[index1 + 7] -= sum * t7;
    }
}
}
