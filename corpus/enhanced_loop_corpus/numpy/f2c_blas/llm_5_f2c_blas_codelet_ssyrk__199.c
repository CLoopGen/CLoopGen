#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

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
    int update_c = (*beta != 1.F);
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real *c_ptr = &c__[i__ + j * c_dim1];
        if (update_c) {
            if (*beta == 0.F) {
                *c_ptr = 0.F;
            } else {
                *c_ptr = *beta * (*c_ptr);
            }
        }
    }
    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        real a_val = a[j + l * a_dim1];
        if (a_val != 0.F) {
            temp = *alpha * a_val;
            i__3 = j;
            for (i__ = 1; i__ <= i__3; ++i__) {
                c__[i__ + j * c_dim1] += temp * a[i__ + l * a_dim1];
            }
        }
    }
}
}
