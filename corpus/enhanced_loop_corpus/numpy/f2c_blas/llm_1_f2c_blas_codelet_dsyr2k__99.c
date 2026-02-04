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
            i__3 = *k;
            for (l = 1; l <= i__3; ++l) {
                if (a[j + l * a_dim1] != 0. || b[j + l * b_dim1] != 0.) {
                    temp1 = *alpha * b[j + l * b_dim1];
                    temp2 = *alpha * a[j + l * a_dim1];
                    c__[i__ + j * c_dim1] += a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
                }
            }
        }
    } else if (*beta != 1.) {
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
            i__3 = *k;
            for (l = 1; l <= i__3; ++l) {
                if (a[j + l * a_dim1] != 0. || b[j + l * b_dim1] != 0.) {
                    temp1 = *alpha * b[j + l * b_dim1];
                    temp2 = *alpha * a[j + l * a_dim1];
                    c__[i__ + j * c_dim1] += a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
                }
            }
        }
    } else {
        i__2 = *k;
        for (l = 1; l <= i__2; ++l) {
            if (a[j + l * a_dim1] != 0. || b[j + l * b_dim1] != 0.) {
                temp1 = *alpha * b[j + l * b_dim1];
                temp2 = *alpha * a[j + l * a_dim1];
                i__3 = j;
                for (i__ = 1; i__ <= i__3; ++i__) {
                    c__[i__ + j * c_dim1] += a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
                }
            }
        }
    }
}
}
