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
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            c__[i__ * c_dim1 + j] = 0.;
        }
    } else if (*beta != 1.) {
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            c__[i__ * c_dim1 + j] = *beta * c__[i__ * c_dim1 + j];
        }
    }
    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        if (a[l * a_dim1 + j] != 0.) {
            temp = *alpha * a[l * a_dim1 + j];
            i__3 = *n;
            for (i__ = j; i__ <= i__3; ++i__) {
                c__[i__ * c_dim1 + j] += temp * a[l * a_dim1 + i__];
            }
        }
    }
}
}
