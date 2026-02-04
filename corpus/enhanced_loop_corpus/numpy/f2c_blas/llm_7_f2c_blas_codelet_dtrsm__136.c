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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= i__1; ++k) {
    doublereal alpha_k = *alpha;
    doublereal diag_inv = nounit ? 1. / a[k + k * a_dim1] : 1.0;
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        doublereal temp_b = b[i__ + k * b_dim1] * diag_inv;
        if (alpha_k != 1.0) {
            temp_b *= alpha_k;
        }
        b[i__ + k * b_dim1] = temp_b;
    }
    for (j = k + 1; j <= *n; ++j) {
        doublereal coeff = a[j + k * a_dim1];
        if (coeff != 0.) {
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + j * b_dim1] = b[i__ + j * b_dim1] - coeff * b[i__ + k * b_dim1];
            }
        }
    }
}
}
