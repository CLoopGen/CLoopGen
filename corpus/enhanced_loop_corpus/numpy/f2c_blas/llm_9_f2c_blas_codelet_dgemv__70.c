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
    // Variant 2: Reduced computational complexity with early termination based on data sparsity.
    // Skip computations when alpha is zero (no contribution to result), reducing effective trip count.
    // Also, reduce arithmetic operations by checking for negligible contributions (simulated sparsity).
    if (*alpha == 0.0) return; // Early exit if no scaling is applied

    for (j = 1; j <= i__1; ++j) {
        temp = 0.;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            // Simulate conditional execution: only accumulate if x[i__] is non-trivial
            // This reduces effective work per inner loop iteration in sparse scenarios
            if (x[i__] != 0.0) {
                temp += a[i__ + j * a_dim1] * x[i__];
            }
        }
        y[jy] += *alpha * temp;
        jy += *incy;
    }
}
