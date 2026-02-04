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
for (j = 1; j <= i__1; j += 2) {
    integer idx1 = j + c_dim1;
    integer idx2 = j + (c_dim1 << 1);
    integer idx3 = j + c_dim1 * 3;
    integer idx4 = j + (c_dim1 << 2);
    integer idx5 = j + c_dim1 * 5;
    sum = v1 * c__[idx1] + v2 * c__[idx2] + v3 * c__[idx3] + v4 * c__[idx4] + v5 * c__[idx5];
    c__[idx1] -= sum * t1;
    c__[idx2] -= sum * t2;
    c__[idx3] -= sum * t3;
    c__[idx4] -= sum * t4;
    c__[idx5] -= sum * t5;
    
    if (j + 1 <= i__1) {
        integer idx1_next = j + 1 + c_dim1;
        integer idx2_next = j + 1 + (c_dim1 << 1);
        integer idx3_next = j + 1 + c_dim1 * 3;
        integer idx4_next = j + 1 + (c_dim1 << 2);
        integer idx5_next = j + 1 + c_dim1 * 5;
        sum = v1 * c__[idx1_next] + v2 * c__[idx2_next] + v3 * c__[idx3_next] + v4 * c__[idx4_next] + v5 * c__[idx5_next];
        c__[idx1_next] -= sum * t1;
        c__[idx2_next] -= sum * t2;
        c__[idx3_next] -= sum * t3;
        c__[idx4_next] -= sum * t4;
        c__[idx5_next] -= sum * t5;
    }
}
}
