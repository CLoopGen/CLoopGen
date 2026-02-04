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
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real temp1 = 0.F, temp2 = 0.F;
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            temp1 += a[l + i__ * a_dim1] * b[l + j * b_dim1];
            if (j + 1 <= i__1) {
                temp2 += a[l + i__ * a_dim1] * b[l + (j + 1) * b_dim1];
            }
        }
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp1;
            if (j + 1 <= i__1) {
                c__[i__ + (j + 1) * c_dim1] = *alpha * temp2;
            }
        } else {
            c__[i__ + j * c_dim1] = *alpha * temp1 + *beta * c__[i__ + j * c_dim1];
            if (j + 1 <= i__1) {
                c__[i__ + (j + 1) * c_dim1] = *alpha * temp2 + *beta * c__[i__ + (j + 1) * c_dim1];
            }
        }
    }
}
}
