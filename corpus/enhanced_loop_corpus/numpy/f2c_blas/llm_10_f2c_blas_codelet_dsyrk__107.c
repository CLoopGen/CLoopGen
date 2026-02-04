#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

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
    integer bound_j1 = j;
    integer bound_j2 = j + 1 > i__1 ? j : j + 1;
    if (*beta == 0.) {
        for (i__ = 1; i__ <= bound_j1; ++i__) {
            c__[i__ + j * c_dim1] = 0.;
        }
        if (bound_j2 == j + 1) {
            for (i__ = 1; i__ <= bound_j2; ++i__) {
                c__[i__ + bound_j2 * c_dim1] = 0.;
            }
        }
    } else if (*beta != 1.) {
        for (i__ = 1; i__ <= bound_j1; ++i__) {
            c__[i__ + j * c_dim1] *= *beta;
        }
        if (bound_j2 == j + 1) {
            for (i__ = 1; i__ <= bound_j2; ++i__) {
                c__[i__ + bound_j2 * c_dim1] *= *beta;
            }
        }
    }
    for (l = 1; l <= *k; ++l) {
        doublereal a_val_j = a[j + l * a_dim1];
        doublereal a_val_jp1 = (j + 1 <= i__1) ? a[(j+1) + l * a_dim1] : 0.;
        if (a_val_j != 0.) {
            temp = *alpha * a_val_j;
            for (i__ = 1; i__ <= j; ++i__) {
                c__[i__ + j * c_dim1] += temp * a[i__ + l * a_dim1];
            }
        }
        if (a_val_jp1 != 0. && j + 1 <= i__1) {
            temp = *alpha * a_val_jp1;
            for (i__ = 1; i__ <= j + 1; ++i__) {
                c__[i__ + (j+1) * c_dim1] += temp * a[i__ + l * a_dim1];
            }
        }
    }
}
}
