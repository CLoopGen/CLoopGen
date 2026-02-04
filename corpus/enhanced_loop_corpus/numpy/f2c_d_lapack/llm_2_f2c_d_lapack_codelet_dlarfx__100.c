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
    // Variant 1: Consecutive memory access by reordering computation to access adjacent elements
    // Assume c_dim1 is large, so we refactor to access consecutive memory locations in inner loop fashion.
    // We unroll the fixed index dimension (1,2,3) into a separate loop for spatial locality.

    doublereal temp[3];
    for (j = 1; j <= i__1; ++j) {
        // Load the three consecutive values into temporary storage for better cache behavior
        temp[0] = c__[j * c_dim1 + 1];
        temp[1] = c__[j * c_dim1 + 2];
        temp[2] = c__[j * c_dim1 + 3];

        sum = v1 * temp[0] + v2 * temp[1] + v3 * temp[2];

        // Update values consecutively
        temp[0] -= sum * t1;
        temp[1] -= sum * t2;
        temp[2] -= sum * t3;

        // Store back
        c__[j * c_dim1 + 1] = temp[0];
        c__[j * c_dim1 + 2] = temp[1];
        c__[j * c_dim1 + 3] = temp[2];
    }
}
