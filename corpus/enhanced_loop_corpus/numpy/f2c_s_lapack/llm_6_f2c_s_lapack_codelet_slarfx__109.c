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
    real temp;
    for (j = 1; j <= i__1; ++j) {
        temp = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)];
        c__[j + c_dim1] -= temp * t1;
        c__[j + (c_dim1 << 1)] -= temp * t2;
    }
}
