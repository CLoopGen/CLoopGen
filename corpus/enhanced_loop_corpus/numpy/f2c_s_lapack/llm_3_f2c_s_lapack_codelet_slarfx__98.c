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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride independent of original index
    // Simulate strided traversal by stepping through every 2nd valid index
    integer stride = 2;
    integer count = (i__1 + stride - 1) / stride; // ceil(i__1 / stride)
    for (j = 1; j <= count; ++j) {
        integer idx = (j * stride - stride + 1); // compute actual index: 1, 3, 5, ...
        if (idx <= i__1) {
            c__[idx * c_dim1 + 1] = t1 * c__[idx * c_dim1 + 1];
        }
    }
}
