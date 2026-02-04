#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern integer *k;
extern real *alpha;
extern real *a;
extern real *b;
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    int beta_case = (*beta == 0.F) ? 0 : (*beta == 1.F) ? 1 : 2;
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        switch (beta_case) {
            case 0:
                c__[i__ + j * c_dim1] = 0.F;
                break;
            case 2:
                c__[i__ + j * c_dim1] *= *beta;
                break;
            default:
                break;
        }
    }
    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        real a_idx = a[j + l * a_dim1];
        real b_idx = b[j + l * b_dim1];
        temp1 = *alpha * b_idx;
        temp2 = *alpha * a_idx;
        i__3 = *n;
        for (i__ = j; i__ <= i__3; ++i__) {
            real update = a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
            c__[i__ + j * c_dim1] += (a_idx != 0.F || b_idx != 0.F) ? update : 0.F;
        }
    }
}
}
