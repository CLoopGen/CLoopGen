#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = (j <= i__1) ? j : j - 1;
    for (k = 1; k <= i__2 - 1; ++k) {
        doublereal a_kj1 = a[k + j * a_dim1];
        doublereal a_kj2 = (j + 1 <= i__1) ? a[k + (j+1) * a_dim1] : 0.0;
        if (a_kj1 != 0.0) {
            for (i__ = 1; i__ <= *m; ++i__) {
                b[i__ + j * b_dim1] -= a_kj1 * b[i__ + k * b_dim1];
            }
        }
        if (a_kj2 != 0.0 && j + 1 <= i__1) {
            for (i__ = 1; i__ <= *m; ++i__) {
                b[i__ + (j+1) * b_dim1] -= a_kj2 * b[i__ + k * b_dim1];
            }
        }
    }
    if (nounit) {
        temp = 1. / a[j + j * a_dim1];
        for (i__ = 1; i__ <= *m; ++i__) {
            b[i__ + j * b_dim1] *= temp;
        }
        if (j + 1 <= i__1) {
            temp = 1. / a[j+1 + (j+1) * a_dim1];
            for (i__ = 1; i__ <= *m; ++i__) {
                b[i__ + (j+1) * b_dim1] *= temp;
            }
        }
    }
    if (*alpha != 1.) {
        for (i__ = 1; i__ <= *m; ++i__) {
            b[i__ + j * b_dim1] *= *alpha;
            if (j + 1 <= i__1) {
                b[i__ + (j+1) * b_dim1] *= *alpha;
            }
        }
    }
}
}
