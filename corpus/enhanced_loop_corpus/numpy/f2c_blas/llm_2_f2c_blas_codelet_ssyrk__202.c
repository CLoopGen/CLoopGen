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
for (j = 1; j <= i__1; ++j) {
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        temp = 0.F;
        i__3 = *k;
        // Change memory access to use consecutive indexing via pointer arithmetic
        real *a_ptr_i = &a[i__ * a_dim1 + 1]; // Base pointer for column i
        real *a_ptr_j = &a[j * a_dim1 + 1];   // Base pointer for column j
        for (l = 1; l <= i__3; ++l) {
            temp += a_ptr_i[l] * a_ptr_j[l];  // Consecutive access through offset pointers
        }
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp;
        } else {
            c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[i__ + j * c_dim1];
        }
    }
}
}
