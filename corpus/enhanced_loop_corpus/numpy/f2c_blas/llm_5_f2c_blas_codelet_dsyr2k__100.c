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
        c__[i__ + j * c_dim1] = (*beta == 0.) ? 0. : ((*beta == 1.) ? c__[i__ + j * c_dim1] : *beta * c__[i__ + j * c_dim1]);
    }
    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        doublereal ajl = a[j + l * a_dim1];
        doublereal bjl = b[j + l * b_dim1];
        if (ajl != 0. || bjl != 0.) {
            temp1 = *alpha * bjl;
            temp2 = *alpha * ajl;
            i__3 = *n;
            for (i__ = j; i__ <= i__3; ++i__) {
                doublereal ail = a[i__ + l * a_dim1];
                doublereal bil = b[i__ + l * b_dim1];
                c__[i__ + j * c_dim1] += ail * temp1 + bil * temp2;
            }
        }
    }
}
}
