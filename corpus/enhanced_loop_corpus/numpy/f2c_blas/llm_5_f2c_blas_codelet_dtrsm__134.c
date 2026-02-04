#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern integer *n;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    logical apply_alpha = (*alpha != 1.);
    logical apply_scaling = nounit;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        doublereal *bp = &b[i__ + j * b_dim1];
        if (apply_alpha) {
            *bp = *alpha * *bp;
        }
        if (apply_scaling) {
            temp = 1. / a[j + j * a_dim1];
            *bp = temp * *bp;
        }
    }
    i__1 = *n;
    for (k = j + 1; k <= i__1; ++k) {
        doublereal a_val = a[k + j * a_dim1];
        if (a_val != 0.) {
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + j * b_dim1] -= a_val * b[i__ + k * b_dim1];
            }
        }
    }
}
}
