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
    // Variant 2: Strided memory access with increased stride to simulate irregular access pattern
    // Simulate a transposed view or strided traversal by stepping through indices with a larger stride
    // This variant accesses every other element (or based on a stride factor), skipping some entries.
    // For realism, we use a fixed stride of 2 and adjust loop bound accordingly.

    integer stride = 2;
    integer bound = (i__1 + stride - 1) / stride; // Ceiling division to cover all needed iterations

    for (j = 1; j <= bound; ++j) {
        integer idx = (j * stride); // Access every second index
        if (idx > i__1) break;

        sum = v1 * c__[idx + c_dim1] + 
              v2 * c__[idx + (c_dim1 << 1)] + 
              v3 * c__[idx + c_dim1 * 3] + 
              v4 * c__[idx + (c_dim1 << 2)];

        c__[idx + c_dim1] -= sum * t1;
        c__[idx + (c_dim1 << 1)] -= sum * t2;
        c__[idx + c_dim1 * 3] -= sum * t3;
        c__[idx + (c_dim1 << 2)] -= sum * t4;
    }
}
