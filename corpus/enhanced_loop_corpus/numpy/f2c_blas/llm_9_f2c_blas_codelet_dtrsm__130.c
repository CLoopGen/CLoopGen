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
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (*alpha != 1.) {
            b[i__ + j * b_dim1] *= *alpha;
            if (j + 1 <= i__1) {
                b[i__ + (j+1) * b_dim1] *= *alpha;
            }
        }
    }
    for (k = 1; k <= i__2; ++k) {
        doublereal bkj1 = b[k + j * b_dim1];
        doublereal bkj2 = (j + 1 <= i__1) ? b[k + (j+1) * b_dim1] : 0.0;
        logical nonzero1 = bkj1 != 0.;
        logical nonzero2 = bkj2 != 0. && (j + 1 <= i__1);
        if (nonzero1 || nonzero2) {
            if (nounit) {
                if (nonzero1) {
                    bkj1 /= a[k + k * a_dim1];
                    b[k + j * b_dim1] = bkj1;
                }
                if (nonzero2) {
                    bkj2 /= a[k + k * a_dim1];
                    b[k + (j+1) * b_dim1] = bkj2;
                }
            }
            i__3 = *m;
            for (i__ = k + 1; i__ <= i__3; ++i__) {
                if (nonzero1) {
                    b[i__ + j * b_dim1] -= bkj1 * a[i__ + k * a_dim1];
                }
                if (nonzero2) {
                    b[i__ + (j+1) * b_dim1] -= bkj2 * a[i__ + k * a_dim1];
                }
            }
        }
    }
}
}
