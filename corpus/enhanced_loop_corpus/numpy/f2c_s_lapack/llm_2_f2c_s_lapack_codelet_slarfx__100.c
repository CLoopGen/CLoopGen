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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize data access to use consecutive memory locations by transposing the implied matrix access.
    // Assume c__ is stored in row-major order now for sequential stride-1 access.
    real *base;
    for (j = 1; j <= i__1; ++j) {
        base = &c__[j]; // Point to start of column j (now treated as row j in row-major)
        sum = v1 * base[c_dim1 * 0] + v2 * base[c_dim1 * 1] + v3 * base[c_dim1 * 2];
        base[c_dim1 * 0] -= sum * t1;
        base[c_dim1 * 1] -= sum * t2;
        base[c_dim1 * 2] -= sum * t3;
    }
}
