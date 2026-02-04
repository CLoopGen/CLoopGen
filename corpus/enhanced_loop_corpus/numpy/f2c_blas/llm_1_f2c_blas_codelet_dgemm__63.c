#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
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
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (*beta == 0.) {
    for (j = 1; j <= i__1; ++j) {
        for (l = 1; l <= *k; ++l) {
            for (i__ = 1; i__ <= *m; ++i__) {
                temp = a[l + i__ * a_dim1] * b[j + l * b_dim1];
                c__[i__ + j * c_dim1] += temp;
            }
        }
        for (i__ = 1; i__ <= *m; ++i__) {
            c__[i__ + j * c_dim1] *= *alpha;
        }
    }
} else {
    for (j = 1; j <= i__1; ++j) {
        for (i__ = 1; i__ <= *m; ++i__) {
            temp = 0.;
            for (l = 1; l <= *k; ++l) {
                temp += a[l + i__ * a_dim1] * b[j + l * b_dim1];
            }
            c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[i__ + j * c_dim1];
        }
    }
}
}
