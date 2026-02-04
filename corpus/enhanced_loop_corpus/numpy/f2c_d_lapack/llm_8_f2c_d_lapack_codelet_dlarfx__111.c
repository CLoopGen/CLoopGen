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
    // Variant 1: Increased computational intensity by unrolling the loop and increasing arithmetic operations per iteration
    integer remainder = i__1 % 4;
    integer bound = i__1 - remainder;

    for (j = 1; j <= bound; j += 4) {
        // Process 4 iterations at once with additional arithmetic to increase computation load
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)];
        c__[j + c_dim1] -= sum * t1;
        c__[j + (c_dim1 << 1)] -= sum * t2;
        c__[j + c_dim1 * 3] -= sum * t3;
        c__[j + (c_dim1 << 2)] -= sum * t4;

        sum = v1 * c__[j+1 + c_dim1] + v2 * c__[j+1 + (c_dim1 << 1)] + v3 * c__[j+1 + c_dim1 * 3] + v4 * c__[j+1 + (c_dim1 << 2)];
        c__[j+1 + c_dim1] -= sum * t1;
        c__[j+1 + (c_dim1 << 1)] -= sum * t2;
        c__[j+1 + c_dim1 * 3] -= sum * t3;
        c__[j+1 + (c_dim1 << 2)] -= sum * t4;

        sum = v1 * c__[j+2 + c_dim1] + v2 * c__[j+2 + (c_dim1 << 1)] + v3 * c__[j+2 + c_dim1 * 3] + v4 * c__[j+2 + (c_dim1 << 2)];
        c__[j+2 + c_dim1] -= sum * t1;
        c__[j+2 + (c_dim1 << 1)] -= sum * t2;
        c__[j+2 + c_dim1 * 3] -= sum * t3;
        c__[j+2 + (c_dim1 << 2)] -= sum * t4;

        sum = v1 * c__[j+3 + c_dim1] + v2 * c__[j+3 + (c_dim1 << 1)] + v3 * c__[j+3 + c_dim1 * 3] + v4 * c__[j+3 + (c_dim1 << 2)];
        c__[j+3 + c_dim1] -= sum * t1;
        c__[j+3 + (c_dim1 << 1)] -= sum * t2;
        c__[j+3 + c_dim1 * 3] -= sum * t3;
        c__[j+3 + (c_dim1 << 2)] -= sum * t4;
    }

    // Handle remaining elements
    for (; j <= i__1; ++j) {
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)];
        c__[j + c_dim1] -= sum * t1;
        c__[j + (c_dim1 << 1)] -= sum * t2;
        c__[j + c_dim1 * 3] -= sum * t3;
        c__[j + (c_dim1 << 2)] -= sum * t4;
    }
}
