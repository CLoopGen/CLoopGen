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
    // Variant 1: Increased loop nesting depth by splitting the inner loop into two sequential inner loops
    for (j = *n; j >= 1; --j) {
        if (x[jx] != 0.) {
            temp = x[jx];
            ix = kx;
            i__1 = j + 1;
            // First inner loop: handle computation for even indices in the range
            for (i__ = *n; i__ >= i__1; --i__) {
                if ((i__ - j) % 2 == 0) {  // Even offset from j
                    x[ix] += temp * a[i__ + j * a_dim1];
                }
            }
            // Second inner loop: handle computation for odd indices in the range
            ix = kx;
            for (i__ = *n; i__ >= i__1; --i__) {
                if ((i__ - j) % 2 == 1) {  // Odd offset from j
                    x[ix] += temp * a[i__ + j * a_dim1];
                    ix -= *incx;
                } else {
                    // Adjust pointer only when not processing, to maintain correct alignment
                    if (ix > kx - (*n - j) * *incx) {
                        ix -= *incx;
                    }
                }
            }
            if (nounit) {
                x[jx] *= a[j + j * a_dim1];
            }
        }
        jx -= *incx;
    }
}
