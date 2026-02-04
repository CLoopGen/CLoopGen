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
for (j = 1; j <= i__1; j += 2) {
    for (integer j2 = 0; j2 < 2 && j + j2 <= i__1; ++j2) {
        integer j_adj = j + j2;
        if (*beta == 0.) {
            i__2 = j_adj;
            for (i__ = 1; i__ <= i__2; ++i__) {
                c__[i__ + j_adj * c_dim1] = 0.;
            }
        } else if (*beta != 1.) {
            i__2 = j_adj;
            for (i__ = 1; i__ <= i__2; ++i__) {
                c__[i__ + j_adj * c_dim1] = *beta * c__[i__ + j_adj * c_dim1];
            }
        }
        i__2 = *k;
        for (l = 1; l <= i__2; ++l) {
            doublereal a_val = a[j_adj + l * a_dim1];
            doublereal b_val = b[j_adj + l * b_dim1];
            if (a_val != 0. || b_val != 0.) {
                temp1 = *alpha * b_val;
                temp2 = *alpha * a_val;
                i__3 = j_adj;
                for (i__ = 1; i__ <= i__3; ++i__) {
                    c__[i__ + j_adj * c_dim1] += a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
                }
            }
        }
    }
}
}
