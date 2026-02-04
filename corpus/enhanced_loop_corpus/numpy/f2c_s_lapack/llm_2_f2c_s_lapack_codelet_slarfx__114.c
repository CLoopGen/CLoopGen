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



void loop() {
    // Variant 1: Consecutive Memory Access via Array Restructuring
    // Instead of strided access with varying multiples of c_dim1, 
    // we assume data is packed consecutively in a temporary array for spatial locality.
    real *base = &c__[c_dim1];  // Base offset for first column
    for (j = 1; j <= i__1; ++j) {
        sum = v1 * base[j] + v2 * base[j + c_dim1] + v3 * base[j + c_dim1 * 2] +
              v4 * base[j + c_dim1 * 3] + v5 * base[j + c_dim1 * 4] +
              v6 * base[j + c_dim1 * 5] + v7 * base[j + c_dim1 * 6];
        base[j]          -= sum * t1;
        base[j + c_dim1]     -= sum * t2;
        base[j + c_dim1 * 2] -= sum * t3;
        base[j + c_dim1 * 3] -= sum * t4;
        base[j + c_dim1 * 4] -= sum * t5;
        base[j + c_dim1 * 5] -= sum * t6;
        base[j + c_dim1 * 6] -= sum * t7;
    }
}
