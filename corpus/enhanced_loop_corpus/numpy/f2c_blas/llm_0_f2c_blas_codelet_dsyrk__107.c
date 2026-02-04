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
    if (*beta == 0.) {
        for (i__ = 1; i__ <= j; ++i__) {
            c__[i__ + j * c_dim1] = 0.;
        }
    } else if (*beta != 1.) {
        for (i__ = 1; i__ <= j; ++i__) {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
        }
    }
    for (l = 1; l <= *k; ++l) {
        if (a[j + l * a_dim1] != 0.) {
            temp = *alpha * a[j + l * a_dim1];
            for (i__ = 1; i__ <= j; ++i__) {
                c__[i__ + j * c_dim1] += temp * a[i__ + l * a_dim1];
            }
        }
    }
}
}
