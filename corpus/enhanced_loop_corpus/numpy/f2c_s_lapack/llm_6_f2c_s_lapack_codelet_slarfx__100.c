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
extern real v1;
extern real v2;
extern real v3;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    real temp_sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3];
    real temp_t1 = temp_sum * t1;
    real temp_t2 = temp_sum * t2;
    real temp_t3 = temp_sum * t3;
    c__[j * c_dim1 + 1] -= temp_t1;
    c__[j * c_dim1 + 2] -= temp_t2;
    c__[j * c_dim1 + 3] -= temp_t3;
}
}
