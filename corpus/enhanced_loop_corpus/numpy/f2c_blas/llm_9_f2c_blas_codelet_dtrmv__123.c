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
    // Variant 2: Reduced trip count and modified computational structure
    // Only process every other element in outer loop (step of 2), reducing total iterations by ~half.
    // Inner loop is simplified to a fixed small range to decrease computational load.
    for (j = *n; j >= 1; j -= 2) {  // Process only odd indices, reduce trip count
        if (x[jx] != 0.) {
            temp = x[jx];
            ix = kx;
            i__1 = j + 1;

            // Limit inner loop to at most 3 iterations regardless of j
            integer upper_bound = (j + 3 > *n) ? *n : j + 3;
            for (i__ = upper_bound; i__ >= i__1 && i__ >= 1; --i__) {
                x[ix] += temp * a[i__ + j * a_dim1];
                ix -= *incx;
            }

            if (nounit) {
                x[jx] *= a[j + j * a_dim1];
            }
        }

        // Also update jx accordingly for skipped j-1 iteration
        jx -= *incx;
        if (j > 1) {
            jx -= *incx;
        }
    }
}
