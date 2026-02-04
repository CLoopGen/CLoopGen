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
extern integer i__1;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern integer kx;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop (factor of 2)
    // This reduces loop overhead and increases arithmetic operations per iteration.
    for (j = *n; j >= 1; --j) {
        if (x[jx] != 0.) {
            temp = x[jx];
            ix = kx;
            i__1 = j + 1;
            i__ = *n;

            // Unroll inner loop by factor of 2
            integer remainder = (*n - j) % 2;
            for (; i__ >= i__1 + remainder; i__ -= 2) {
                x[ix] += temp * a[i__ + j * a_dim1];
                ix -= *incx;
                x[ix] += temp * a[i__ - 1 + j * a_dim1];
                ix -= *incx;
            }
            // Handle leftover iteration if any
            for (; i__ >= i__1; --i__) {
                x[ix] += temp * a[i__ + j * a_dim1];
                ix -= *incx;
            }

            if (nounit) {
                x[jx] *= a[j + j * a_dim1];
            }
        }
        jx -= *incx;
    }
}
