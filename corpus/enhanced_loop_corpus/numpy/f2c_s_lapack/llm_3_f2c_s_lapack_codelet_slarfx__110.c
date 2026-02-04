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
    // Variant 2: Strided memory access with increased stride to simulate irregular access pattern
    // Simulate a strided traversal by introducing a fixed stride (e.g., every 4th element)
    // This could model scenarios with padding or non-unit stride in higher-level data structures.

    const integer stride = 4;
    const integer offset1 = c_dim1;
    const integer offset2 = c_dim1 << 1;
    const integer offset3 = c_dim1 * 3;

    for (j = 1; j <= i__1; j += stride) {
        // Ensure index bounds are respected assuming i__1 is divisible by stride
        sum = v1 * c__[j + offset1] + v2 * c__[j + offset2] + v3 * c__[j + offset3];
        c__[j + offset1] -= sum * t1;
        c__[j + offset2] -= sum * t2;
        c__[j + offset3] -= sum * t3;
    }

    // Handle remaining elements if i__1 is not a multiple of stride
    for (; j <= i__1; ++j) {
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3];
        c__[j + c_dim1] -= sum * t1;
        c__[j + (c_dim1 << 1)] -= sum * t2;
        c__[j + c_dim1 * 3] -= sum * t3;
    }
}
