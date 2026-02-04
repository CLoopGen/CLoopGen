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
for (j = 1; j <= i__1; j += 2) {
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        temp1 = 0.;
        temp2 = 0.;
        i__3 = *k / 2;
        for (l = 1; l <= i__3; ++l) {
            temp1 += (a[l + i__ * a_dim1] + a[l + i__ * a_dim1 + a_dim1]) * 
                     (b[l + j * b_dim1] + b[l + j * b_dim1 + b_dim1]);
            temp2 += (b[l + i__ * b_dim1] + b[l + i__ * b_dim1 + b_dim1]) * 
                     (a[l + j * a_dim1] + a[l + j * a_dim1 + a_dim1]);
        }
        if (*beta == 0.) {
            c__[i__ + j * c_dim1] = *alpha * temp1 + *alpha * temp2;
        } else {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1] + *alpha * temp1 + *alpha * temp2;
        }
        if (j + 1 <= i__1) {
            c__[i__ + (j+1) * c_dim1] = *beta * c__[i__ + (j+1) * c_dim1] + *alpha * temp1 + *alpha * temp2;
        }
    }
}
}
