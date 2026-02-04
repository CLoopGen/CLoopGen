#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *n;
extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations.
    // The inner loop is partially unrolled to process two iterations at once, doubling the arithmetic per iteration.
    // This increases computational intensity without changing the trip count significantly.

    for (j = *n; j >= 1; --j) {
        if (x[j] != 0.) {
            temp = x[j];
            i__1 = j + 1;
            i__ = *n;

            // Unroll inner loop by factor of 2
            while (i__ >= i__1 + 1) {
                x[i__] += temp * a[i__ + j * a_dim1];
                x[i__-1] += temp * a[(i__-1) + j * a_dim1];
                i__ -= 2;
            }
            // Handle remaining iteration if count is odd
            if (i__ == i__1) {
                x[i__] += temp * a[i__ + j * a_dim1];
            }

            if (nounit) {
                x[j] *= a[j + j * a_dim1];
            }
        }
    }
}
