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
extern doublereal t5;
extern doublereal t6;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access elements with a fixed stride across the array, simulating non-contiguous access
    // Here, we traverse each column component separately in a strided manner
    integer idx;
    sum = 0.0;
    for (j = 1; j <= i__1; ++j) {
        idx = j * c_dim1;
        // Accumulate using strided access: each array element accessed with increasing offset
        sum += v1 * c__[idx + 1] + v2 * c__[idx + 2] + v3 * c__[idx + 3] +
               v4 * c__[idx + 4] + v5 * c__[idx + 5] + v6 * c__[idx + 6];
    }
    // Now apply updates with same strided pattern
    for (j = 1; j <= i__1; ++j) {
        idx = j * c_dim1;
        c__[idx + 1] -= sum * t1 / i__1;  // Normalize contribution over iterations
        c__[idx + 2] -= sum * t2 / i__1;
        c__[idx + 3] -= sum * t3 / i__1;
        c__[idx + 4] -= sum * t4 / i__1;
        c__[idx + 5] -= sum * t5 / i__1;
        c__[idx + 6] -= sum * t6 / i__1;
    }
}
