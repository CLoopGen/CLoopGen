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
for (j = 1; j <= i__1; ++j) {
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp1 = 0.F;
        temp2 = 0.F;
        i__3 = *k;
        // Change memory access to use pointer arithmetic with consecutive loads
        real *a_ptr = &a[i__ * a_dim1 + 1];
        real *b_ptr = &b[j * b_dim1 + 1];
        real *b_iptr = &b[i__ * b_dim1 + 1];
        real *a_jptr = &a[j * a_dim1 + 1];
        for (l = 1; l <= i__3; ++l) {
            temp1 += a_ptr[l] * b_ptr[l];     // Consecutive access via base pointers
            temp2 += b_iptr[l] * a_jptr[l];
        }
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp1 + *alpha * temp2;
        } else {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1] + *alpha * temp1 + *alpha * temp2;
        }
    }
}
}
