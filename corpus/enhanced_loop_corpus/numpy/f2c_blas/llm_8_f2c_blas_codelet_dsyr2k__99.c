#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *k;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern doublereal *beta;
extern doublereal *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    if (*beta == 0.) {
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            c__[i__ + j * c_dim1] = 0.;
        }
    } else if (*beta != 1.) {
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            c__[i__ + j * c_dim1] *= *beta;
        }
    }
    temp1 = 0.;
    temp2 = 0.;
    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        doublereal a_val = a[j + l * a_dim1];
        doublereal b_val = b[j + l * b_dim1];
        if (a_val != 0. || b_val != 0.) {
            doublereal alpha_a = *alpha * a_val;
            doublereal alpha_b = *alpha * b_val;
            i__3 = j;
            for (i__ = 1; i__ <= i__3; ++i__) {
                doublereal a_i = a[i__ + l * a_dim1];
                doublereal b_i = b[i__ + l * b_dim1];
                c__[i__ + j * c_dim1] += a_i * alpha_b + b_i * alpha_a;
            }
        }
    }
}
}
