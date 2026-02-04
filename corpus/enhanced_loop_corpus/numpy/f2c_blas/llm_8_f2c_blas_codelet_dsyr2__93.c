#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *alpha;
extern doublereal *x;
extern doublereal *y;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop by a factor of 2
    // and increasing arithmetic operations per iteration to raise FLOP count.
    for (j = 1; j <= i__1; ++j) {
        if (x[j] != 0. || y[j] != 0.) {
            temp1 = *alpha * y[j];
            temp2 = *alpha * x[j];
            i__2 = *n;
            i__ = j;
            // Unroll by 2: process two iterations at once
            for (; i__ <= i__2 - 1; i__ += 2) {
                doublereal xi0 = x[i__], yi0 = y[i__];
                doublereal xi1 = x[i__+1], yi1 = y[i__+1];
                a[i__   + j * a_dim1] += xi0 * temp1 + yi0 * temp2;
                a[i__+1 + j * a_dim1] += xi1 * temp1 + yi1 * temp2;
            }
            // Handle remaining element if any
            if (i__ <= i__2) {
                a[i__ + j * a_dim1] += x[i__] * temp1 + y[i__] * temp2;
            }
        }
    }
}
