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
for (j = 1; j <= i__1; ++j) {
    if (*beta == 0.) {
        for (i__ = 1; i__ <= *m; ++i__) {
            *(c__ + i__ + j * c_dim1) = 0.0;
        }
    } else if (*beta != 1.) {
        for (i__ = 1; i__ <= *m; ++i__) {
            *(c__ + i__ + j * c_dim1) *= *beta;
        }
    }
    for (l = 1; l <= *k; ++l) {
        integer idx_b = j + l * b_dim1;
        if (*(b + idx_b) != 0.0) {
            temp = *alpha * *(b + idx_b);
            for (i__ = 1; i__ <= *m; ++i__) {
                integer idx_a = i__ + l * a_dim1;
                integer idx_c = i__ + j * c_dim1;
                *(c__ + idx_c) += temp * *(a + idx_a);
            }
        }
    }
}
}
