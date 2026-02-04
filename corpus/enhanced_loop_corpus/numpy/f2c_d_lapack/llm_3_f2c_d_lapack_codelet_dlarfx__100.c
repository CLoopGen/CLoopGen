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
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - simulate processing every other column (strided pattern)
    // This variant introduces a stride of 2 in the j-loop, accessing only odd-indexed columns.
    // Maintains correctness under assumption that such access is valid within data bounds.

    integer stride = 2;
    integer j_max = (i__1 % 2 == 0) ? i__1 - 1 : i__1;  // Ensure we don't exceed bounds

    for (j = 1; j <= j_max; j += stride) {
        sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3];
        c__[j * c_dim1 + 1] -= sum * t1;
        c__[j * c_dim1 + 2] -= sum * t2;
        c__[j * c_dim1 + 3] -= sum * t3;
    }

    // Handle any remaining column if i__1 is not aligned with stride (e.g., even i__1)
    if (i__1 >= 1 && i__1 % 2 == 0) {
        j = i__1;
        sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3];
        c__[j * c_dim1 + 1] -= sum * t1;
        c__[j * c_dim1 + 2] -= sum * t2;
        c__[j * c_dim1 + 3] -= sum * t3;
    }
}
