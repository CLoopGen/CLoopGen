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
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t base_index = j * c_dim1;
    sum = v1 * c__[base_index + 1] + v2 * c__[base_index + 2] + v3 * c__[base_index + 3] + 
          v4 * c__[base_index + 4] + v5 * c__[base_index + 5] + v6 * c__[base_index + 6] + 
          v7 * c__[base_index + 7] + v8 * c__[base_index + 8] + v9 * c__[base_index + 9];
    c__[base_index + 1] -= sum * t1;
    c__[base_index + 2] -= sum * t2;
    c__[base_index + 3] -= sum * t3;
    c__[base_index + 4] -= sum * t4;
    c__[base_index + 5] -= sum * t5;
    c__[base_index + 6] -= sum * t6;
    c__[base_index + 7] -= sum * t7;
    c__[base_index + 8] -= sum * t8;
    c__[base_index + 9] -= sum * t9;
}
}
