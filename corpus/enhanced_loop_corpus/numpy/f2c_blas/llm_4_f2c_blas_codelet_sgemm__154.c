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
        real* c_ptr = &c__[i__ + j * c_dim1];
        if (*beta == 0.F) {
            *c_ptr = 0.F;
        } else if (*beta != 1.F) {
            *c_ptr = *beta * (*c_ptr);
        }
        temp = 0.F;
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            if (b[j + l * b_dim1] != 0.F) {
                temp += *alpha * b[j + l * b_dim1] * a[i__ + l * a_dim1];
            }
        }
        *c_ptr += temp;
    }
}
}
