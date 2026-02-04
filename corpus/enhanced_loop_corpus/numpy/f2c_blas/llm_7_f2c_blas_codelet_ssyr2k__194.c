#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
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
// Reverse loop order to change loop-carried dependencies and memory access pattern
// This variant reverses the outer loop and adjusts indexing accordingly
for (j = i__1; j >= 1; --j) {
    i__2 = *n;
    for (i__ = i__2; i__ >= j; --i__) {
        temp1 = 0.F;
        temp2 = 0.F;
        i__3 = *k;
        // Modify inner loop to unroll by factor 2 (if applicable) and fuse operations to alter data dependencies
        // Here we simulate partial unrolling effect by processing two elements at a time where possible
        l = 1;
        // Handle even number of iterations with dual accumulation to introduce intra-loop dependency fusion
        for (; l <= i__3 - 1; l += 2) {
            // Combine two iterations to create new dependency edges (fused accumulation), reducing loop overhead
            temp1 += a[l   + i__ * a_dim1] * b[l   + j * b_dim1] +
                     a[l+1 + i__ * a_dim1] * b[l+1 + j * b_dim1];
            temp2 += b[l   + i__ * b_dim1] * a[l   + j * a_dim1] +
                     b[l+1 + i__ * b_dim1] * a[l+1 + j * a_dim1];
        }
        // Handle remaining element if k is odd
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
