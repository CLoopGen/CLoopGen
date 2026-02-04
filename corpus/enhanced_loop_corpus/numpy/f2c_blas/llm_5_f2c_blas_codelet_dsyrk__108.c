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
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        c__[i__ + j * c_dim1] = (*beta == 0.0) ? 0.0 : ((*beta == 1.0) ? c__[i__ + j * c_dim1] : *beta * c__[i__ + j * c_dim1]);
    }
    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        doublereal a_val = a[j + l * a_dim1];
        if (a_val != 0.) {
            temp = *alpha * a_val;
            i__3 = *n;
            for (i__ = j; i__ <= i__3; ++i__) {
                c__[i__ + j * c_dim1] += temp * a[i__ + l * a_dim1];
            }
        }
    }
}
}
