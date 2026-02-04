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
    for (integer jj = 0; jj < 2 && j + jj <= i__1; ++jj) {
        integer col = j + jj;
        if (*beta == 0.) {
            for (i__ = 1; i__ <= *m; ++i__) {
                c__[i__ + col * c_dim1] = 0.;
            }
        } else if (*beta != 1.) {
            for (i__ = 1; i__ <= *m; ++i__) {
                c__[i__ + col * c_dim1] *= *beta;
            }
        }
        for (l = 1; l <= *k; ++l) {
            doublereal b_val = b[col + l * b_dim1];
            if (b_val != 0.) {
                temp = *alpha * b_val;
                for (i__ = 1; i__ <= *m; ++i__) {
                    c__[i__ + col * c_dim1] += temp * a[i__ + l * a_dim1];
                }
            }
        }
    }
}
}
