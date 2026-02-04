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
for (j = 1; j <= i__1; ++j) {
    if (*alpha != 1.) {
        b[0 + j * b_dim1] = *alpha * b[0 + j * b_dim1];
        for (i__ = 2; i__ <= *m; ++i__) {
            b[i__ - 1 + j * b_dim1] = *alpha * b[i__ - 1 + j * b_dim1];
        }
    }
    for (k = 1; k <= j - 1; ++k) {
        if (a[k + j * a_dim1] != 0.) {
            for (i__ = 1; i__ <= *m; ++i__) {
                b[i__ + j * b_dim1] -= a[k + j * a_dim1] * b[i__ + k * b_dim1];
            }
        }
    }
    if (nounit) {
        temp = 1. / a[j + j * a_dim1];
        for (i__ = 1; i__ <= *m; ++i__) {
            b[i__ + j * b_dim1] = temp * b[i__ + j * b_dim1];
        }
    }
}
}
