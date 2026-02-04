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
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Modify access pattern to use strided access with explicit stride handling
for (j = 1; j <= i__1; ++j) {
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        temp = 0.F;
        i__3 = *k;
        integer stride_a = 1; // Simulate strided access (could be tuned)
        for (l = 1; l <= i__3; ++l) {
            // Access elements using non-unit stride in the inner loop
            integer idx_a_i = (l - 1) * stride_a + i__ * a_dim1 + 1;
            integer idx_a_j = (l - 1) * stride_a + j * a_dim1 + 1;
            temp += a[idx_a_i] * a[idx_a_j];
        }
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp;
        } else {
            c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[i__ + j * c_dim1];
        }
    }
}
}
