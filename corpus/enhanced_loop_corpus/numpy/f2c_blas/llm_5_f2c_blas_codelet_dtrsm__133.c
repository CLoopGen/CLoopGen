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
    logical apply_alpha = (*alpha != 1.);
    logical apply_scaling = nounit && (a[j + j * a_dim1] != 0.);
    
    if (apply_alpha) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ + j * b_dim1] = *alpha * b[i__ + j * b_dim1];
        }
    }

    i__2 = j - 1;
    for (k = 1; k <= i__2; ++k) {
        doublereal a_val = a[k + j * a_dim1];
        if (a_val != 0.) {
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + j * b_dim1] -= a_val * b[i__ + k * b_dim1];
            }
        }
    }

    if (apply_scaling) {
        temp = 1. / a[j + j * a_dim1];
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ + j * b_dim1] *= temp;
        }
    }
}
}
