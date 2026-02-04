#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *alpha;
extern real *a;
extern real *x;
extern real *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse loop iteration order to alter loop-carried dependencies (if any were present)
    // Also restructure computation to accumulate temp2 before updating y elements
    for (j = i__1; j >= 1; --j) {
        temp1 = *alpha * x[j];
        temp2 = 0.F;
        i__2 = *n;

        // Precompute temp2 using reversed dependency to change data flow
        for (i__ = i__2; i__ >= j + 1; --i__) {
            temp2 += a[i__ + j * a_dim1] * x[i__];
        }

        // Update y[j] with combined term early
        y[j] += temp1 * a[j + j * a_dim1] + *alpha * temp2;

        // Now apply the vector update in forward direction within reverse outer loop
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            y[i__] += temp1 * a[i__ + j * a_dim1];
        }
    }
}
