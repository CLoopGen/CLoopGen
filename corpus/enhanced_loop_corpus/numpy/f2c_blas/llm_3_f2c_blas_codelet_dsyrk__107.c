#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *k;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *beta;
extern doublereal *c__;
extern integer a_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t c_base = j * c_dim1;
    ptrdiff_t a_col_offset = l * a_dim1;
    if (*beta == 0.) {
        for (i__ = 1; i__ <= j; ++i__) {
            c__[i__ + c_base] = 0.;
        }
    } else if (*beta != 1.) {
        for (i__ = 1; i__ <= j; ++i__) {
            c__[i__ + c_base] = *beta * c__[i__ + c_base];
        }
    }
    for (l = 1; l <= *k; ++l) {
        a_col_offset = l * a_dim1;
        if (a[j + a_col_offset] != 0.) {
            temp = *alpha * a[j + a_col_offset];
            for (i__ = 1; i__ <= j; ++i__) {
                c__[i__ + c_base] += temp * a[i__ + a_col_offset];
            }
        }
    }
}
}
