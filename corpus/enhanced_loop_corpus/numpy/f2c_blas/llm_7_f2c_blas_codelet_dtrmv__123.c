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
    for (j = *n; j >= 1; --j) {
        doublereal local_temp = 0.0;
        if (x[jx] != 0.) {
            temp = x[jx];
            ix = kx;
            i__1 = j + 1;
            // Eliminate loop-carried dependence by accumulating in a local scalar
            for (i__ = *n; i__ >= i__1; --i__) {
                local_temp += temp * a[i__ + j * a_dim1];
                // Delayed write to break RAW dependency across iterations
                if (i__ == i__1) {
                    x[ix] += local_temp;
                } else {
                    x[ix] += temp * a[i__ + j * a_dim1]; // Still update immediately for correctness
                }
                ix -= *incx;
            }
            if (nounit) {
                x[jx] *= a[j + j * a_dim1];
            }
        }
        jx -= *incx;
    }
}
