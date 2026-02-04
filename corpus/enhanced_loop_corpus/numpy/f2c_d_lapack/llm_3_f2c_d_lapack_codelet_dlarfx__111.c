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
extern doublereal t2;
extern doublereal t3;
extern doublereal t4;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride to simulate non-unit stride traversal
    // We modify the access pattern to step through the array with a fixed increment (e.g., every 2nd element)
    // This could model scenarios where only even-indexed or decimated data points are processed.
    // Note: Assumes i__1 is adjusted accordingly if needed, but original bound is preserved.

    integer stride = 2;
    integer limit = i__1 / stride;

    for (j = 1; j <= limit; ++j) {
        integer idx = j * stride;  // Compute actual index using stride
        sum = v1 * c__[idx + c_dim1] + v2 * c__[idx + (c_dim1 << 1)] +
              v3 * c__[idx + c_dim1 * 3] + v4 * c__[idx + (c_dim1 << 2)];
        c__[idx + c_dim1] -= sum * t1;
        c__[idx + (c_dim1 << 1)] -= sum * t2;
        c__[idx + c_dim1 * 3] -= sum * t3;
        c__[idx + (c_dim1 << 2)] -= sum * t4;
    }
}
