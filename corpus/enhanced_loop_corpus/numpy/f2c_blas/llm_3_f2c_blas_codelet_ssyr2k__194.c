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
for (j = 1; j <= i__1; ++j) {
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        temp1 = 0.F;
        temp2 = 0.F;
        i__3 = *k;
        integer a_offset, b_offset;
        for (l = 1; l <= i__3; ++l) {
            a_offset = l + i__ * a_dim1;
            b_offset = l + j * b_dim1;
            temp1 += a[a_offset] * b[b_offset];
            a_offset = l + j * a_dim1;
            b_offset = l + i__ * b_dim1;
            temp2 += b[b_offset] * a[a_offset];
        }
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp1 + *alpha * temp2;
        } else {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1] + *alpha * temp1 + *alpha * temp2;
        }
    }
}
}
