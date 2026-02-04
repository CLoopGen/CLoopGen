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
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        doublereal temp1 = 0., temp2 = 0.;
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            temp1 += a[l + i__ * a_dim1] * b[j + l * b_dim1];
            if (j + 1 <= i__1) {
                temp2 += a[l + i__ * a_dim1] * b[j + 1 + l * b_dim1];
            }
        }
        c__[i__ + j * c_dim1] = *alpha * temp1 + *beta * c__[i__ + j * c_dim1];
        if (j + 1 <= i__1) {
            c__[i__ + (j + 1) * c_dim1] = *alpha * temp2 + *beta * c__[i__ + (j + 1) * c_dim1];
        }
    }
}
}
