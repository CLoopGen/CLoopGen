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
    temp2 = *beta;
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real *c_ptr = &c__[i__ + j * c_dim1];
        if (temp2 == 0.F) {
            *c_ptr = 0.F;
        } else if (temp2 != 1.F) {
            *c_ptr = temp2 * (*c_ptr);
        }
        real sum_temp = *c_ptr;
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            real a_val = a[j + l * a_dim1];
            real b_val = b[j + l * b_dim1];
            if (a_val != 0.F || b_val != 0.F) {
                temp1 = *alpha * b_val;
                temp2 = *alpha * a_val;
                sum_temp += a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
            }
        }
        *c_ptr = sum_temp;
    }
}
}
