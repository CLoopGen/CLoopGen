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
        real *c_index = &c__[i__ + j * c_dim1];
        *c_index *= (*beta == 0.F) ? 0.F : (*beta == 1.F ? 1.F : *beta);
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            real a_val = a[j + l * a_dim1];
            temp = *alpha * a_val;
            if (a_val != 0.F) {
                *c_index += temp * a[i__ + l * a_dim1];
            }
        }
    }
}
}
