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
extern integer i__;
extern integer j;
extern integer k;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    integer j2 = j + 1;
    if (*alpha != 1.) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ + j * b_dim1] *= *alpha;
            if (j2 <= i__1) {
                b[i__ + j2 * b_dim1] *= *alpha;
            }
        }
    }
    for (k = *m; k >= 1; --k) {
        logical update1 = (b[k + j * b_dim1] != 0.);
        logical update2 = (j2 <= i__1 && b[k + j2 * b_dim1] != 0.);
        if (update1 || update2) {
            doublereal temp1 = b[k + j * b_dim1];
            doublereal temp2 = j2 <= i__1 ? b[k + j2 * b_dim1] : 0.;
            if (nounit) {
                if (update1) temp1 /= a[k + k * a_dim1];
                if (update2) temp2 /= a[k + k * a_dim1];
            }
            if (update1) b[k + j * b_dim1] = temp1;
            if (update2) b[k + j2 * b_dim1] = temp2;
            i__2 = k - 1;
            for (i__ = 1; i__ <= i__2; ++i__) {
                if (update1) {
                    b[i__ + j * b_dim1] -= temp1 * a[i__ + k * a_dim1];
                }
                if (update2) {
                    b[i__ + j2 * b_dim1] -= temp2 * a[i__ + k * a_dim1];
                }
            }
        }
    }
}
}
