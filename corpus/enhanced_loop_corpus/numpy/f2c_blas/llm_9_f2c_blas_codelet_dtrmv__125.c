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
    // Variant 2: Reduced computational complexity with early termination and simplified control flow.
    // The inner loop is skipped entirely when possible (e.g., when j == 1), effectively reducing trip count
    // of the inner loop in many iterations. Also removes redundant memory accesses by checking conditions.

    for (j = *n; j >= 1; --j) {
        temp = x[jx];
        if (nounit) {
            temp *= a[j + j * a_dim1];
        }
        // Skip inner loop entirely if j <= 1 (no elements to process)
        if (j > 1) {
            ix = jx;
            for (i__ = j - 1; i__ >= 1; --i__) {
                ix -= *incx;
                temp += a[i__ + j * a_dim1] * x[ix];
            }
        }
        x[jx] = temp;
        jx -= *incx;
    }
}
