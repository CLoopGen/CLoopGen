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
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp1 = 0.;
        temp2 = 0.;
        i__3 = *k;
        // Change memory access to use pointer arithmetic with consecutive increments
        doublereal *pa = &a[i__ * a_dim1 + 1];
        doublereal *pb = &b[j * b_dim1 + 1];
        doublereal *pb_i = &b[i__ * b_dim1 + 1];
        doublereal *pa_j = &a[j * a_dim1 + 1];
        for (l = 1; l <= i__3; ++l) {
            temp1 += pa[l] * pb[l];      // Consecutive access in inner loop
            temp2 += pb_i[l] * pa_j[l];  // Consecutive access for symmetry
        }
        if (*beta == 0.) {
            c__[i__ + j * c_dim1] = *alpha * temp1 + *alpha * temp2;
        } else {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1] + *alpha * temp1 + *alpha * temp2;
        }
    }
}
}
