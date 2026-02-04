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
i__2 = *m;
i__3 = *k;
for (i__ = 1; i__ <= i__2; ++i__) {
    for (j = 1; j <= i__1; ++j) {
        temp = 0.;
        for (l = 1; l <= i__3; ++l) {
            temp += a[l + i__ * a_dim1] * b[l + j * b_dim1];
        }
        if (*beta == 0.) {
            c__[i__ + j * c_dim1] = *alpha * temp;
        } else {
            c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[i__ + j * c_dim1];
        }
    }
}
}
