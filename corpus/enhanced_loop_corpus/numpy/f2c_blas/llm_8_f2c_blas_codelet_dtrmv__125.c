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
extern integer *incx;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations.
    // The inner loop is partially unrolled to process two iterations at a time, doubling the number of arithmetic
    // operations per iteration and reducing loop overhead. Trip count remains the same but work per iteration increases.

    for (j = *n; j >= 1; --j) {
        temp = x[jx];
        ix = jx;
        if (nounit) {
            temp *= a[j + j * a_dim1];
        }
        i__ = j - 1;
        // Process two elements at a time in the inner loop
        while (i__ >= 2) {
            int ix1 = ix - *incx;
            int ix2 = ix1 - *incx;
            temp += a[i__   + j * a_dim1] * x[ix1];
            temp += a[i__-1 + j * a_dim1] * x[ix2];
            ix = ix2;
            i__ -= 2;
        }
        // Handle remaining element if any
        if (i__ == 1) {
            ix -= *incx;
            temp += a[i__ + j * a_dim1] * x[ix];
        }
        x[jx] = temp;
        jx -= *incx;
    }
}
