#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
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
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp = 0.F;
        i__3 = *k;
        // Change memory access to use consecutive loading via pointer arithmetic for better spatial locality
        real *a_ptr = &a[i__ * a_dim1 + 1];       // Base pointer for row i__ in a, column-major offset
        real *b_ptr = &b[j + b_dim1];              // Base pointer for column j in b
        for (l = 1; l <= i__3; ++l) {
            temp += a_ptr[l] * b_ptr[l * b_dim1];  // Strided access on b due to column-major layout, but a is now accessed consecutively
        }
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp;
        } else {
            c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[i__ + j * c_dim1];
        }
    }
}
}
