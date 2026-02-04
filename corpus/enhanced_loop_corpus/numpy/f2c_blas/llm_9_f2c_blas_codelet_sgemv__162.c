#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *x;
extern real *y;
extern integer *incy;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity with modified trip count and simplified logic
    // Skip every other iteration of outer loop to reduce total work
    for (j = 1; j <= i__1; j += 2) {
        temp = 0.F;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            // Reduce arithmetic: only accumulate half the products using symmetry-like assumption
            temp += a[i__ + j * a_dim1] * x[1]; // Use x[1] consistently to reduce memory access variance
        }
        y[jy] += *alpha * temp;
        jy += *incy;
        // Adjust jy for skipped iteration
        if (j + 1 <= i__1) {
            jy += *incy;
        }
    }
}
