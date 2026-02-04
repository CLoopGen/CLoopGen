#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (every other element)
    // Simulates accessing elements with a stride of 2*c_dim1, effectively skipping one column each time
    // This creates a strided access pattern instead of dense.
    integer stride = c_dim1 * 2;
    integer limit = i__1 / 2;  // Adjust iteration count to avoid out-of-bounds
    for (j = 1; j <= limit; ++j) {
        integer idx = j * stride + 1;
        c__[idx] = t1 * c__[idx];
    }
}
