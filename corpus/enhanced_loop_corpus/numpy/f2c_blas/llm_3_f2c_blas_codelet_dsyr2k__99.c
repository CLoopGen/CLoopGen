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
const integer stride_a = 2;
const integer stride_b = 2;
const integer stride_c = 2;
for (j = 1; j <= i__1; j += stride_c) {
    for (i__ = 1; i__ <= j; ++i__) {
        if (*beta == 0.) {
            c__[i__ + j * c_dim1] = 0.;
        } else if (*beta != 1.) {
            c__[i__ + j * c_dim1] *= *beta;
        }
        temp1 = 0.;
        temp2 = 0.;
        for (l = 1; l <= *k; l += stride_a) {
            doublereal a_val = a[j + l * a_dim1];
            doublereal b_val = b[j + l * b_dim1];
            if (a_val != 0. || b_val != 0.) {
                temp1 = *alpha * b_val;
                temp2 = *alpha * a_val;
                c__[i__ + j * c_dim1] += a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
            }
        }
    }
}
}
