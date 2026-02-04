#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *k;
extern real *alpha;
extern real *a;
extern real *b;
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependencies by unrolling the inner loop twice
// and reorganizing accumulation to expose parallelism
for (j = 1; j <= i__1; ++j) {
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp1 = 0.F;
        temp2 = 0.F;
        i__3 = *k;

        integer l = 1;
        // Unroll by factor of 2 to reduce loop-carried dependency frequency
        for (; l <= i__3 - 1; l += 2) {
            // Process two iterations at once to change data flow
            temp1 += a[l + i__ * a_dim1] * b[l + j * b_dim1] +
                     a[l+1 + i__ * a_dim1] * b[l+1 + j * b_dim1];
            temp2 += b[l + i__ * b_dim1] * a[l + j * a_dim1] +
                     b[l+1 + i__ * b_dim1] * a[l+1 + j * a_dim1];
        }
        // Handle remainder if k is odd
        if (l <= i__3) {
            temp1 += a[l + i__ * a_dim1] * b[l + j * b_dim1];
            temp2 += b[l + i__ * b_dim1] * a[l + j * a_dim1];
        }

        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp1 + *alpha * temp2;
        } else {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1] + *alpha * temp1 + *alpha * temp2;
        }
    }
}
}
