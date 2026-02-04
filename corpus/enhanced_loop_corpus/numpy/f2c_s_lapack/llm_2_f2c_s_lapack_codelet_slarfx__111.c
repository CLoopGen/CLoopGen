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
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations to access adjacent elements
    // We assume c__ is a 2D array stored in row-major order, and we transpose the access pattern
    // to improve spatial locality. Here, we process multiple rows together for consecutive access.
    
    real *c1 = &c__[c_dim1 + 1];        // j=1 offset for first column block
    real *c2 = &c__[(c_dim1 << 1) + 1]; // j=1 offset for second column block
    real *c3 = &c__[c_dim1 * 3 + 1];    // j=1 offset for third column block
    real *c4 = &c__[(c_dim1 << 2) + 1]; // j=1 offset for fourth column block

    for (j = 1; j <= i__1; ++j) {
        sum = v1 * c1[j] + v2 * c2[j] + v3 * c3[j] + v4 * c4[j];
        c1[j] -= sum * t1;
        c2[j] -= sum * t2;
        c3[j] -= sum * t3;
        c4[j] -= sum * t4;
    }
}
