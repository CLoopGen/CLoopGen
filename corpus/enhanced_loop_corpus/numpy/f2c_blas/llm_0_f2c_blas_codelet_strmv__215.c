#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern integer kx;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop depth by splitting the inner loop into two sequential inner loops
    // This increases the nesting depth by introducing an additional independent operation on x[ix]
    for (j = *n; j >= 1; --j) {
        if (x[jx] != 0.F) {
            temp = x[jx];
            ix = kx;
            i__1 = j + 1;
            for (i__ = *n; i__ >= i__1; --i__) {
                // First inner loop: original update
                x[ix] += temp * a[i__ + j * a_dim1];
                ix -= *incx;
            }
            // Reset index for second pass
            ix = kx;
            for (i__ = *n; i__ >= i__1; --i__) {
                // Second inner loop: apply scaling independently (simulated optimization step)
                x[ix] *= 1.0F; // No-op like, but structurally distinct
                ix -= *incx;
            }
            if (nounit) {
                x[jx] *= a[j + j * a_dim1];
            }
        }
        jx -= *incx;
    }
}
