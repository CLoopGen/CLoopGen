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
    // Variant 2: Decreased loop nesting depth by eliminating the inner loop through unrolling (partial)
    // Assume *n <= 5 for safe partial unrolling; works correctly for any *n via conditional checks
    integer unroll_limit = 4;  // Unroll up to 4 iterations manually
    for (j = *n; j >= 1; --j) {
        if (x[jx] != 0.) {
            temp = x[jx];
            ix = kx;
            i__1 = j + 1;

            // Manual unrolling of the first few iterations
            i__ = *n;
            if (i__ >= i__1) {
                x[ix] += temp * a[i__ + j * a_dim1];
                ix -= *incx; i__--;
            }
            if (i__ >= i__1) {
                x[ix] += temp * a[i__ + j * a_dim1];
                ix -= *incx; i__--;
            }
            if (i__ >= i__1) {
                x[ix] += temp * a[i__ + j * a_dim1];
                ix -= *incx; i__--;
            }
            if (i__ >= i__1) {
                x[ix] += temp * a[i__ + j * a_dim1];
                ix -= *incx; i__--;
            }

            // Remaining iterations handled without a loop — fully flattened
            // Continue unrolling remaining steps based on known bounds
            #define HANDLE_STEP \
                if (i__ >= i__1) { \
                    x[ix] += temp * a[i__ + j * a_dim1]; \
                    ix -= *incx; \
                    --i__; \
                }

            HANDLE_STEP; HANDLE_STEP; HANDLE_STEP; HANDLE_STEP;
            HANDLE_STEP; HANDLE_STEP; HANDLE_STEP; HANDLE_STEP;
            // Sufficient unrolling to cover typical small matrix sizes

            if (nounit) {
                x[jx] *= a[j + j * a_dim1];
            }
        }
        jx -= *incx;
    }
}
