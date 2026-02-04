#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *x;
extern integer *incx;
extern doublereal *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jx;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop 4 times to reduce loop overhead and increase arithmetic operations per iteration.
    for (j = 1; j <= i__1; ++j) {
        if (x[jx] != 0.) {
            temp = *alpha * x[jx];
            i__2 = *m;
            i__ = 1;
            // Unroll by 4
            for (; i__ <= i__2 - 3; i__ += 4) {
                y[i__]     += temp * a[i__     + j * a_dim1];
                y[i__ + 1] += temp * a[i__ + 1 + j * a_dim1];
                y[i__ + 2] += temp * a[i__ + 2 + j * a_dim1];
                y[i__ + 3] += temp * a[i__ + 3 + j * a_dim1];
            }
            // Handle remaining iterations
            for (; i__ <= i__2; ++i__) {
                y[i__] += temp * a[i__ + j * a_dim1];
            }
        }
        jx += *incx;
    }
}
