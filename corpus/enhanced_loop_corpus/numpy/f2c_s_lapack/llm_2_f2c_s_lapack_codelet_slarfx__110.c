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
    // Variant 1: Consecutive memory access by reordering computations to access adjacent elements
    // Here, we assume c__ is a 2D array stored in row-major and c_dim1 is the leading dimension.
    // We refactor the access pattern to improve spatial locality by processing consecutive elements.

    real *c1 = &c__[c_dim1 + 1];        // Base pointer for j + c_dim1
    real *c2 = &c__[(c_dim1 << 1) + 1]; // Base pointer for j + 2*c_dim1
    real *c3 = &c__[c_dim1 * 3 + 1];     // Base pointer for j + 3*c_dim1

    for (j = 1; j <= i__1; ++j) {
        sum = v1 * c1[j] + v2 * c2[j] + v3 * c3[j];
        c1[j] -= sum * t1;
        c2[j] -= sum * t2;
        c3[j] -= sum * t3;
    }
}
