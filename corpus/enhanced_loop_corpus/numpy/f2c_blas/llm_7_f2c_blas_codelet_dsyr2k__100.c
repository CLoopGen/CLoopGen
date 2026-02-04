#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
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
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        if (*beta == 0.) {
            c__[i__ + j * c_dim1] = 0.;
        } else if (*beta != 1.) {
            c__[i__ + j * c_dim1] *= *beta;
        }
        temp1 = 0.0;
        temp2 = 0.0;
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            doublereal a_val = a[j + l * a_dim1];
            doublereal b_val = b[j + l * b_dim1];
            if (a_val != 0. || b_val != 0.) {
                temp1 += a[i__ + l * a_dim1] * b_val;
                temp2 += b[i__ + l * b_dim1] * a_val;
            }
        }
        c__[i__ + j * c_dim1] += *alpha * (temp1 + temp2);
    }
}
}
