#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *x;
extern real *y;
extern integer *incy;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop (2x) and increasing arithmetic operations
    for (j = 1; j <= i__1; ++j) {
        temp = 0.F;
        i__2 = *m;
        i__ = 1;
        // Unroll by 2 to increase arithmetic density
        for (; i__ <= i__2 - 1; i__ += 2) {
            temp += a[i__   + j * a_dim1] * x[i__] +
                    a[i__+1 + j * a_dim1] * x[i__+1];
        }
        // Handle remainder if m is odd
        if (i__ <= i__2) {
            temp += a[i__ + j * a_dim1] * x[i__];
        }
        y[jy] += *alpha * temp;
        jy += *incy;
    }
}
