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
extern doublereal *y;
extern integer *incy;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations.
    // The inner loop is partially unrolled by a factor of 2 to perform two multiplications and additions per iteration,
    // thereby reducing loop overhead and increasing FLOPs per cycle. Trip count adjusted for even *m.
    for (j = 1; j <= i__1; ++j) {
        temp = 0.;
        i__2 = *m;
        i__ = 1;
        // Unroll by 2
        for (; i__ <= i__2 - 1; i__ += 2) {
            temp += a[i__ + j * a_dim1] * x[i__] + a[i__ + 1 + j * a_dim1] * x[i__ + 1];
        }
        // Handle remaining element if *m is odd
        if (i__ <= i__2) {
            temp += a[i__ + j * a_dim1] * x[i__];
        }
        y[jy] += *alpha * temp;
        jy += *incy;
    }
}
