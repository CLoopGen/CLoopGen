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
extern doublereal v1;
extern doublereal v2;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (every other row skipped)
    // Simulate strided access pattern by stepping with stride 2 and adjusting index calculation
    integer stride = 2;
    integer limit = (i__1 / stride) * stride;
    for (j = 1; j <= limit; j += stride) {
        sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2];
        c__[j * c_dim1 + 1] -= sum * t1;
        c__[j * c_dim1 + 2] -= sum * t2;
    }
    // Handle remainder if i__1 is not divisible by stride
    if (limit + 1 <= i__1) {
        j = limit + 1;
        sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2];
        c__[j * c_dim1 + 1] -= sum * t1;
        c__[j * c_dim1 + 2] -= sum * t2;
    }
}
