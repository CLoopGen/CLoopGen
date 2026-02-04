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
for (j = 1; j <= i__1; j += 2) {
    i__2 = (j + 1 <= i__1) ? j + 1 : j;
    for (integer j2 = j; j2 <= i__2; ++j2) {
        if (*beta == 0.) {
            i__3 = *n;
            for (i__ = j2; i__ <= i__3; ++i__) {
                c__[i__ + j2 * c_dim1] = 0.;
            }
        } else if (*beta != 1.) {
            i__3 = *n;
            for (i__ = j2; i__ <= i__3; ++i__) {
                c__[i__ + j2 * c_dim1] = *beta * c__[i__ + j2 * c_dim1];
            }
        }
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            doublereal a_val = a[j2 + l * a_dim1];
            if (a_val != 0.) {
                temp = *alpha * a_val;
                for (i__ = j2; i__ <= *n; ++i__) {
                    c__[i__ + j2 * c_dim1] += temp * a[i__ + l * a_dim1];
                }
            }
        }
    }
}
}
