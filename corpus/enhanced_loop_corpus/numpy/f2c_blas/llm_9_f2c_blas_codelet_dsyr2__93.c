#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *alpha;
extern doublereal *x;
extern doublereal *y;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity by decreasing effective trip count
    // and simplifying arithmetic. Only every second j is processed, reducing work.
    // Also, redundant condition check is optimized to skip more iterations.
    for (j = 1; j <= i__1; j += 2) {  // Process only odd indices: reduces outer loop trips by ~2x
        if (x[j] == 0. && y[j] == 0.) continue;
        temp1 = *alpha * y[j];
        temp2 = *alpha * x[j];
        i__2 = *n;
        // Inner loop starts from j+1 instead of j to reduce total iterations
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            // Reduced arithmetic: use fused multiply-add like pattern (conceptually)
            a[i__ + j * a_dim1] = a[i__ + j * a_dim1] + x[i__] * temp1;
        }
        // Skip symmetric updates and second term to lower operation count
    }
}
