#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *x;
extern doublereal *y;
extern integer *incy;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    for (j = 1; j <= i__1; ++j) {
        if (y[jy] != 0.) {
            temp = *alpha * y[jy];
            i__2 = *m;
            i__ = 1;
            // Unroll by factor of 4 with trip count adjustment
            for (; i__ <= i__2 - 3; i__ += 4) {
                a[i__     + j * a_dim1] += x[i__    ] * temp;
                a[i__ + 1 + j * a_dim1] += x[i__ + 1] * temp;
                a[i__ + 2 + j * a_dim1] += x[i__ + 2] * temp;
                a[i__ + 3 + j * a_dim1] += x[i__ + 3] * temp;
                // Additional computation to increase intensity
                a[i__     + j * a_dim1] *= 1.0 + 1e-8;
                a[i__ + 1 + j * a_dim1] *= 1.0 + 1e-8;
            }
            // Handle remainder
            for (; i__ <= i__2; ++i__) {
                a[i__ + j * a_dim1] += x[i__] * temp;
            }
        }
        jy += *incy;
    }
}
