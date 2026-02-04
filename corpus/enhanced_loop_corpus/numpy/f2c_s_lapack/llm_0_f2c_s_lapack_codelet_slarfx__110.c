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
    integer j_outer, j_inner;
    for (j_outer = 1; j_outer <= i__1; j_outer += 2) {
        for (j_inner = j_outer; j_inner < j_outer + 2 && j_inner <= i__1; ++j_inner) {
            j = j_inner;
            sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3];
            c__[j + c_dim1] -= sum * t1;
            c__[j + (c_dim1 << 1)] -= sum * t2;
            c__[j + c_dim1 * 3] -= sum * t3;
        }
    }
}
