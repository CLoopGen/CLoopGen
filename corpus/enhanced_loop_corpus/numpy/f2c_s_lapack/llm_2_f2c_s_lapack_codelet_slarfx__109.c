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
    // Variant 1: Consecutive memory access by restructuring array layout access
    // Instead of accessing c__[j + c_dim1] and c__[j + (c_dim1 << 1)] which are strided,
    // we assume a transposed or flattened view where elements are accessed consecutively.
    // We simulate consecutive access by introducing local pointers that step linearly.

    real *base1 = &c__[c_dim1 + 1];      // Points to c__[1 + c_dim1]
    real *base2 = &c__[(c_dim1 << 1) + 1]; // Points to c__[1 + 2*c_dim1]

    for (j = 0; j < i__1; ++j) {
        sum = v1 * base1[j] + v2 * base2[j];
        base1[j] -= sum * t1;
        base2[j] -= sum * t2;
    }
}
