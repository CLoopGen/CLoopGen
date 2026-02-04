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
extern real v1;
extern real v2;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    integer base_index = j * c_dim1;
    sum = v1 * c__[base_index + 1] + v2 * c__[base_index + 2];
    c__[base_index + 1] -= sum * t1;
    c__[base_index + 2] -= sum * t2;

    if (j + 1 <= i__1) {
        integer next_index = (j + 1) * c_dim1;
        sum = v1 * c__[next_index + 1] + v2 * c__[next_index + 2];
        c__[next_index + 1] -= sum * t1;
        c__[next_index + 2] -= sum * t2;
    }
}
}
